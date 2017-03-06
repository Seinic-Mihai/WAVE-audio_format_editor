#include "wave.h"

void	wave_reverse(wave_t *w)
{

	uint32_t	i;
	uint32_t	size = W_DATA_SIZE(w);
	char		tmp[size];
	uint32_t	j;

	i = 0;
	j = size;
	if (W_DATA(w) != NULL)
	{
		while (j > 0)
		{
			tmp[i] = W_DATA(w)[j];
			i++;
			j--;
		}
		i = 0;
		while (i < size)
		{
			W_DATA(w)[i] = tmp[i];
			i++;
		}
	}
}
