#include "project.h"
#include "args.h"

void    print_error(void)
{
        printf("No wave loaded\n");
}

void    opt_load(const char * str)
{
        if (!(g_wave = wave_load(str)))
                printf("Failed to load!\n");
        else
                printf("Loaded ok!\n");
}

void    opt_save(const char * str)
{
        if (!g_wave)
                printf("Nothing to save\n");    
        else
        {
                wave_save(str, g_wave); 
                printf("Saved ok!\n");
        }
}

void    opt_info(void)
{
        if (!g_wave)
                print_error();
        else
                info_wave(g_wave);
}

void    opt_scale(double s)
{
        if (!g_wave)
                print_error();
        else
        {
                wave_scale(g_wave, s);
                printf("Scaled ok!\n");
        }
}

void    opt_reverse(void)
{
        if (!g_wave)
                print_error();
        else
        {
                wave_reverse(g_wave);
                printf("Reversed ok!\n");
        }
}

void    opt_mono(void)
{
        if (!g_wave)
                print_error();
        else
        {
                g_wave = wave_canal(g_wave, 1);
                printf("Mono transformation ok!\n");
        }
}

void    opt_stereo(void)
{
        if (!g_wave)
                print_error();
        else
        {
                g_wave = wave_canal(g_wave, 2);
                printf("Stereo transformation ok!\n");
        }
}

void    opt_6(void)
{
        if (!g_wave)
                print_error();
        else
        {
                g_wave = wave_canal(g_wave, 6);
                printf("5.1 transformation ok!\n");
        }
}

void    opt_free(option_t *opt)
{
        if (opt != NULL)
        {
                opt_free(opt->next);
                free(opt);
        }
}
