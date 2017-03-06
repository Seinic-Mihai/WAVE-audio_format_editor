#include "wave.h"

wave_t	*wave_canal(wave_t *wave, uint16_t c)
{
	wave_t *w;
	uint32_t k = 0;
	uint32_t i = 0;
	uint16_t j = 0;

	w = wave_new(W_SAMPLE_RATE(wave),W_BITS_PER_SAMPLE(wave),c,W_DATA_SIZE(wave)/W_BLOCK_ALIGN(wave));
	if(W_CHANNELS(wave) > c)
	{
		while (i < W_DATA_SIZE(wave))
		{
			j = 0;
			while (j < c * W_BITS_PER_SAMPLE(wave) / 8)
			{
				W_DATA(w)[k] = W_DATA(wave)[i + j];
				k++;
				j++;
			}
			i += W_BLOCK_ALIGN(wave);
		}
	}
	else
	{ 
		while (i < W_DATA_SIZE(wave))
		{
			j = 0;
			while (j < c * W_BITS_PER_SAMPLE(wave) / 8)
			{
				if (j < W_CHANNELS(wave))
					W_DATA(w)[k] = W_DATA(wave)[i+j];
				else
					W_DATA(w)[k] = W_DATA(wave)[i + W_CHANNELS(wave) - 1];
				k++;
				j++;
			}
			i += W_BLOCK_ALIGN(wave);
		}
	}
	wave_delete(&wave);
	return (w);
}
