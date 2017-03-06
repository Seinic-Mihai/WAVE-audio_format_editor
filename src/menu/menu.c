# include "menu.h"
# include "project.h"
# include <stdlib.h>

void	clear_screen(void)
{
	system("clear||@cls");
}

menu_t  *createMenu(const char *str)
{
	menu_t  *menu;

	if (!(menu = (menu_t *)malloc(sizeof(menu_t))))
		return (menu);
	bzero(menu, sizeof(menu_t));
	if (str != NULL)
		menu->description = strdup(str);
	return (menu);
}
void    addMenuAction(menu_t *menu, const char *str, void (*f)())
{
	size_t  size;

	size = 0;
	while (size < MENU_SIZE && ITEM_EXISTS(menu->items[size].type))
		size++;
	if (f != NULL && size < MENU_SIZE)
	{
		menu->items[size].data.action.function = f;
		if (str != NULL)
			menu->items[size].data.action.description = strdup(str);
		menu->items[size].type = ACTION;
	}
}

void    addSubMenu(menu_t *menu, menu_t *sub_menu)
{
	size_t  size;

	size = 0;
	if (menu != NULL && sub_menu != NULL)
	{
		while (size < MENU_SIZE && ITEM_EXISTS(menu->items[size].type))
			size++;
		if (size < MENU_SIZE)
		{
			menu->items[size].data.sub_menu = sub_menu;
			menu->items[size].data.sub_menu->menu_parent = menu;
			menu->items[size].type = SUB_MENU;
		}
	}
}

static void	ft_strdel(char **as)
{
	ft_memdel((void **)as);
}

void    deleteMenu(menu_t *menu)
{
	size_t size;

	size = 0;
	if (menu != NULL)
	{
		while (size < MENU_SIZE)
		{
			if (menu->items[size].type == ACTION)
			{
				ft_strdel(&menu->items[size].data.action.description);
				menu->items[size].data.action.function = NULL;
				menu->items[size].type = DEFAULT;
			}
			else if (menu->items[size].type == SUB_MENU)
			{
				deleteMenu(menu->items[size].data.sub_menu);
				menu->items[size].type = DEFAULT;
			}
			size++;
		}
		ft_strdel(&menu->description);
		ft_memdel((void **)&menu);
	}
}

static void	print_action(int size, char *str)
{
	printf("\033[1;33m");
	printf("\t\t\t%d", size);
	printf("\033[0m");
	printf(" - ");
	printf("\033[1;32m");
	printf("%s\n\n", str);
	printf("\033[0m");
}

static void	print_submenu(int size, char *str)
{
	printf("\033[1;33m");
	printf("\t\t\t%d", size);
	printf("\033[0m");
	printf(" - ");	
	printf("\033[1;34m");
	printf("%s\n\n", str);
	printf("\033[0m");
}

static void	print_menu_description(char *str)
{
	printf("\n\033[1;91m");
	printf("\t\t\t\t%s\n\n", str);
	printf("\033[0m");
}

static void	print_unknown()
{
	printf("Unknown command, try again.\n");
}

static void	exec_function(char *str, void(*f)())
{	
	printf("%s\n", str);
	if (f != NULL)
		f();
}

static void	print_menu_items(menu_t *menu)
{
	int	size;

	size = 0;
	clear_screen();
	print_menu_description(menu->description);
	while (size < MENU_SIZE)
	{
		if (menu->items[size].type == ACTION)
			print_action(size + 1, menu->items[size].data.action.description);

		else if (menu->items[size].type == SUB_MENU)
			print_submenu(size + 1, menu->items[size].data.sub_menu->description);
		size++;
	}
	printf("\033[1;33m");
	printf("\t\t\t( p - to go menu before)");
	printf("\033[0m");			

}

char	ret_read(void)
{	
	char	str[1024];
	int	i;

	bzero(str,1024);
	i = 0;
	printf("\n\033[1;36m");
	printf("make a choice: ");
	printf("\033[0m");
	while ((str[i] = getchar()) != '\n' && i < 1023)
		i++;
	if (i == 1)
		return (str[0]);
	return (0);
}

void    launchMenu(menu_t *menu)
{
	int    buff;

	if (menu != NULL)
	{
		print_menu_items(menu);
		do {
			buff = ret_read();
			if (buff >= '1' && buff <= '9')
			{
				if (menu->items[buff - '0' - 1].type == SUB_MENU)
					launchMenu(menu->items[buff - '0' - 1].data.sub_menu);
				if (menu->items[buff - '0' - 1].type == ACTION)
					exec_function(menu->items[buff - '0' - 1].data.action.description, menu->items[buff - '0' - 1].data.action.function);

			}
			else if (buff == 'p')
			{
				if (menu->menu_parent != NULL)
					print_menu_items(menu->menu_parent);
				break;

			}
			else
				print_unknown(buff);
		} while (count == 0);
	}
}
