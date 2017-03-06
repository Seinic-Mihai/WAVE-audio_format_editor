#ifndef MENU_H
# define MENU_H
# define MENU_SIZE 9
# define DEFAULT 0
# define ACTION 'a'
# define SUB_MENU 's'
# define RED	"\e[31m"
# define YELLOW	"\e[93m"
# define GREEN	"\e[32m"
# define BLUE	"\e[34m"
# define END_C	"\e[39m"
# define ITEM_EXISTS(x) (x == ACTION ? 1 : x == SUB_MENU ? 1 : 0)
# include <stdio.h>
# include <stdlib.h>
# include <string.h> 
# include <strings.h> 

typedef struct 			action_s
{
	char			*description;
	void			(*function)();
}				action_t;

typedef union			data
{
	struct menu_s		*sub_menu;
	action_t		action;				
}				data_u;

typedef struct			item_s
{
	char			type;
	data_u			data;
}				item_t;

typedef struct 			menu_s
{
	struct menu_s		*menu_parent;
	char			*description;
	item_t			items[MENU_SIZE];
}				menu_t;

menu_t				*createMenu(const char *str);
void				addMenuAction(menu_t* m, const char* text, void(*f)());
void				addSubMenu(menu_t* m, menu_t* sm);
void				deleteMenu(menu_t* m);
void				launchMenu(menu_t* m);

#endif
