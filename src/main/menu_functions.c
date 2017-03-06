#include "project.h"
#include "stdio.h"
void    lol(void)
{
	printf("...\n");
}

void    quit(void)
{
	count = 1;
}

void    wave_info(void)
{
	if (!g_wave)
		print_error();
	else
		info_wave(g_wave);
}

void    inverser(void)
{
	if (!g_wave)
		print_error();
	else
		wave_reverse(g_wave);
}
void    scale(void)
{
	double  s;  

	if (!g_wave)
		print_error();
	else
	{
		printf("Enter the value: ");
		scanf("%lf",&s);
		wave_scale(g_wave, s); 
	}
}

void    save(void)
{
	char buff[1025] = {0};
	if (!g_wave)
		print_error();
	else
	{
		printf("Enter the filename: ");
		scanf("%1024s",buff);
		getc(stdin);
		if (wave_save(buff, g_wave))
			printf("Saved!\n");
		else
			printf("Error while saving.\n");
	}
}

void    wave_canal_mono(void)
{
	if (!g_wave)
		print_error();
	else
	{
		g_wave = wave_canal(g_wave, 1);
		printf("Mono transformation ok!\n");
		save();
	}
}

void    wave_canal_stereo(void)
{
	if (!g_wave)
		print_error();
	else
	{
		g_wave = wave_canal(g_wave, 2);
		printf("Stereo transformation ok!\n");
		save();
	}
}

void    wave_canal_6(void)
{
	if (!g_wave)
		print_error();
	else
	{
		g_wave = wave_canal(g_wave, 6);
		printf("5.1 transformation ok!\n");
		save();
	}
}


static void    load_tmp(void)
{
	char buff[1025] = {0};
	printf("Enter the filename of file to load: ");
	scanf("%1024s",buff);
	getc(stdin);
	if (!(g_wave = wave_load(buff)))
		printf("Failed to load!\n");
	else
		printf("Loaded ok!\n");
}

void    load(void)
{
	char buff[1025] = {0};
	char ch[4] = {0};

	if (g_wave)
	{
		while (1)
		{
			bzero(ch, 4);
			printf("Do you want to save the existing wave file? (yes or no) :");
			scanf(" %3s",ch);
			if (!strcmp(ch,"yes") || !strcmp(ch,"no"))
				break;
		}
		if (!strcmp(ch, "yes"))
		{
			printf("Enter the filename: ");
			scanf("%1024s",buff);
			if (wave_save(buff, g_wave))
				printf("Saved!\n");
			else
				printf("Error while saving.\n");
			load_tmp();
		}
		else if (!strcmp(ch, "no"))
		{
			wave_delete(&g_wave);
			load_tmp();
		}
	}
	else
		load_tmp();
}

void    crop(void)
{
	temp_t          start;
	temp_t          end;
	uint32_t        s;
	uint32_t        e;
	uint32_t        tmp;

	if (!g_wave)
		print_error();
	else
	{
		printf("set the starting time in format h:min:sec\n");
		time_get(g_wave, &start);
		s = temp_oct(g_wave, &start);
		printf("set the ending time in format h:min:sec\n");
		time_get(g_wave, &end);
		e = temp_oct(g_wave, &end);
		tmp = 0;
		if (s > e)
		{
			tmp = s;
			s = e;
			e = tmp;
		}
		wave_crop(g_wave, s, e);
	}
}

void    create_sin()
{
	wave_t  *new_wave = wave_new(22050,16,1,160000);
	add_signal(new_wave, sin);
	if (wave_save("sin.wav", new_wave))
		printf("Saved!\n");
	else
		printf("Error while saving.\n");
	wave_delete(&new_wave);
	printf("sin.wav Created. (mono 16bit)\n");
}

void    create_cos()
{
	wave_t  *new_wave = wave_new(22050,16,1,160000);
	add_signal(new_wave, cos);
	if (wave_save("cos.wav", new_wave))
		printf("Saved!\n");
	else
		printf("Error while saving.\n");

	wave_delete(&new_wave);
	printf("cos.wav Created. (mono 16bit)\n");
}

void    create_tan()
{
	wave_t  *new_wave = wave_new(44100,16,1,160000);
	add_signal(new_wave, tan);
	if (wave_save("tan.wav", new_wave))
		printf("Saved!\n");
	else
		printf("Error while saving.\n");

	wave_delete(&new_wave);
	printf("tan.wav Created. (mono 16bit)\n");
}

void    wave_c1(void)
{
	if (!g_wave)
		print_error();
	else
	{
		g_wave = wave_canal(g_wave, 1);
		printf("1 Canaux transformation ok!\n");
	}
}

void    wave_c2(void)
{
	if (!g_wave)
		print_error();
	else
	{
		g_wave = wave_canal(g_wave, 2);
		printf("2 Canaux transformation ok!\n");
	}
}

void    wave_c3(void)
{
	if (!g_wave)
		print_error();
	else
	{
		g_wave = wave_canal(g_wave, 3);
		printf("3 Canaux transformation ok!\n");
	}
}

void    wave_c4(void)
{
	if (!g_wave)
		print_error();
	else
	{
		g_wave = wave_canal(g_wave, 4);
		printf("4 Canaux transformation ok!\n");
	}
}

void    wave_c5(void)
{
	if (!g_wave)
		print_error();
	else
	{
		g_wave = wave_canal(g_wave, 5);
		printf("5 Canaux transformation ok!\n");
	}
}

void    wave_c6(void)
{
	if (!g_wave)
		print_error();
	else
	{
		g_wave = wave_canal(g_wave, 6);
		printf("6 Canaux transformation ok!\n");
	}
}

void	new_header()
{
	uint32_t	f;
	uint16_t	p;
	uint16_t	c;
	uint32_t	B;

	f = 0;
	p = 0;
	c = 0;
	B = 0;
	printf("Enter the value of sample_rate (f):");
	scanf("%u",&f);
	printf("Enter the value of bits_per_sample (p) (8, 16, 24):");
	scanf("%hu",&p);
	printf("Enter the value of Channels (c) (1-6):");
	scanf("%hu",&c);
	printf("Enter the value of Blocks (B):");
	scanf("%u",&B);

	g_wave = wave_new(f,p,c,B);
	if (!check_header(g_wave))
	{
		fprintf(stderr,"Bad formated WAV header.\n");
		wave_delete(&g_wave);
		return;
	}
	add_signal(g_wave, sin);
}

void	new_audio(void)
{
	char buff[1025] = {0};
	char ch[4] = {0};

	if (g_wave)
	{
		while (1)
		{
			bzero(ch, 4);
			printf("Do you want to save the existing wave file? (yes or no) :");
			scanf(" %3s",ch);
			if (!strcmp(ch,"yes") || !strcmp(ch,"no"))
				break;
		}
		if (!strcmp(ch, "yes"))
		{
			printf("Enter the filename: ");
			scanf("%1024s",buff);
			if (wave_save(buff, g_wave))
				printf("Saved!\n");
			else
				printf("Error while saving.\n");

			printf("Saved!\n");
			new_header();
		}
		else if (!strcmp(ch, "no"))
		{
			wave_delete(&g_wave);
			new_header();
		}
	}
	else
		new_header();

}
