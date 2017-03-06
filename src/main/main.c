#include "project.h"
#include "menu.h"
#include "wave.h"
#include "args.h"

int	count = 0;
int	ret = 0;
wave_t	*g_wave = NULL;

menu_t	*create_project_menu()
{
	menu_t	*menu;
	menu_t	*sub_menu[5];
	menu_t	*sub_menu1;
	int	i;

	menu = createMenu("Main Menu");

	sub_menu[0] = createMenu("Fichier");

	addMenuAction(sub_menu[0],"Ouvrir",load);
	sub_menu1 = createMenu("Enregistrer");
	addSubMenu(sub_menu[0],sub_menu1);

	addMenuAction(sub_menu1,"Souvgarder le wav courant",save);
	addMenuAction(sub_menu1,"WAVE Mono Transformation",wave_canal_mono);
	addMenuAction(sub_menu1,"WAVE Stereo Transformation",wave_canal_stereo);
	addMenuAction(sub_menu1,"WAVE 5.1 Transformation",wave_canal_6);

	addMenuAction(sub_menu[0],"Information Wave",wave_info);
	addMenuAction(sub_menu[0],"Quitter",quit);

	sub_menu[1] = createMenu("Duree et tempo");
	addMenuAction(sub_menu[1],"Inverser",inverser);
	addMenuAction(sub_menu[1],"Decouper",crop);
	addMenuAction(sub_menu[1],"Redimensionner",scale);

	sub_menu[2] = createMenu("Canaux");
	addMenuAction(sub_menu[2],"1 Canaux",wave_c1);
	addMenuAction(sub_menu[2],"2 Canaux",wave_c2);
	addMenuAction(sub_menu[2],"3 Canaux",wave_c3);
	addMenuAction(sub_menu[2],"4 Canaux",wave_c4);
	addMenuAction(sub_menu[2],"5 Canaux",wave_c5);
	addMenuAction(sub_menu[2],"6 Canaux",wave_c6);

	sub_menu[3] = createMenu("Hauteur");
	sub_menu[4] = createMenu("Create new wav file");
	addMenuAction(sub_menu[4],"Manual New WAV with sin signal",new_audio);
	
	addMenuAction(sub_menu[4],"create wav exemple with sin signal",create_sin);
	addMenuAction(sub_menu[4],"create wav exemple with cos signal",create_cos);
	addMenuAction(sub_menu[4],"create wav exemple with tan signal",create_tan);

	i = 0;
	while (i < 5)
	{
		addSubMenu(menu,sub_menu[i]);
		i++;
	}
	addMenuAction(menu,"Quitter",quit);
	return (menu);
}

int main(int ac, char **av)
{
	menu_t		*menu = NULL;
	option_t	*opt = NOOPTION;
	if (ac == 1)
	{
		menu = create_project_menu();
		count = 0;
		while (count == 0)
			launchMenu(menu);
		deleteMenu(menu);
	}
	else
	{
		opt = opt_string(opt, "-l", opt_load);
		opt = opt_string(opt, "-load", opt_load);
		opt = opt_string(opt, "-s", opt_save);
		opt = opt_string(opt, "-save", opt_save);
		opt = opt_void(opt, "-i", opt_info);
		opt = opt_void(opt, "-info", opt_info);
		opt = opt_void(opt, "-r", opt_reverse);
		opt = opt_void(opt, "-reverse", opt_reverse);
		opt = opt_void(opt, "-mono", opt_mono);
		opt = opt_void(opt, "-stereo", opt_stereo);
		opt = opt_void(opt, "-6", opt_6);
		opt = opt_double(opt, "-scale", opt_scale);
		process_arguments(opt, ac, av);
		opt_free(opt);
	}
	if (g_wave)
		wave_delete(&g_wave);
	return (0);
}
