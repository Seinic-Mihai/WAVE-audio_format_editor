#ifndef PROJECT_H
# define PROJECT_H
# include "menu.h"
# include <strings.h>
# include <string.h>
# include "wave.h"
# include "args.h"

typedef struct	temp_s
{
	int	h;
	int	m;
	int	s;
}		temp_t;


/****************************************/

/*
**	Functions that are used in menu
**
**
**
*/

void		lol(void);
void		quit(void);
void		wave_info(void);
void		inverser(void);
void		scale(void);
void		save(void);
void		wave_canal_mono(void);
void		wave_canal_stereo(void);
void		wave_canal_6(void);
void		load(void);
void		crop(void);
void		create_sin(void);
void		create_cos(void);
void		create_tan(void);
void		wave_c1(void);
void		wave_c2(void);
void		wave_c3(void);
void		wave_c4(void);
void		wave_c5(void);
void		wave_c6(void);
void		new_audio(void);

/****************************************/

/*
**	Functions that are used for crop
**
**
**
*/

void		set_time(temp_t *t);
uint32_t	temp_oct(wave_t *w, temp_t *t);
int		check_time(wave_t *w, temp_t *t);
void		time_get(wave_t *w, temp_t *t);

/****************************************/

/*
**	Functions for error message
**
**
**
*/

void		print_error(void);

/****************************************/

/*
**	Functions that are used as options
**
**
**
*/

void		save_tmp(wave_t w);
void		ft_memdel(void **ptr);
void		opt_load(const char * str);
void		opt_save(const char * str);
void		opt_info(void);
void		opt_scale(double s);
void		opt_reverse(void);
void		opt_mono(void);
void		opt_stereo(void);
void		opt_6(void);
void		opt_free(option_t *opt);

/****************************************/

/*
**	Globals
**
**
**
*/

extern int	count;
extern int	ret;
extern wave_t	*g_wave;

/****************************************/
#endif
