#include "wave.h"

void	wave_crop(wave_t *w, uint32_t start, uint32_t end)
{
	uint32_t	crop_size;
	char		*tmp;
	uint32_t	i;
	uint32_t	j;

	crop_size = end - start;
	if (!(tmp = (char*)malloc(sizeof(char) * crop_size)))
	{	
		fprintf(stderr,"malloc error in wave_crop\n");
		return;
	}
	i = start;
	j = 0;
	while (j < crop_size)
	{
		tmp[j] = W_DATA(w)[i];
		i++;
		j++;
	}
	free(w->data);
	w->data = tmp;
	W_DATA_SIZE(w) = crop_size;
}
