#include "project.h"

void    set_time(temp_t *t)
{
        printf("h = ");
        scanf("%d",&(t->h));
        printf("min = ");
        scanf("%d",&(t->m));
        printf("sec = ");
        scanf("%d",&(t->s));
	getc(stdin);
}

uint32_t        temp_oct(wave_t *w, temp_t *t)
{
        uint32_t        ret;
        float           s;
        s = (t->h) * 3600 + (t->m) * 60 + t->s;
        ret = (uint32_t)(s * W_BYTE_RATE(w));
        return (ret);
}

int     check_time(wave_t *w, temp_t *t)
{
        uint32_t        tmp;

        tmp = temp_oct(w,t);
        return ((tmp < W_DATA_SIZE(w)));
}

void    time_get(wave_t *w, temp_t *t)
{
        set_time(t);
        while (!(check_time(w, t)))
        {
                printf("Error you entered a wrong time\n");
                set_time(t);
        }
        printf("Time for crop set Ok!\n");
}
