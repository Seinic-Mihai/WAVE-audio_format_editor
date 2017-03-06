#include "wave.h"

void wave_set(wave_t *w, uint32_t i, uint16_t j, int64_t a)
{
	int8_t sample8bit;
        int16_t sample16bit;
        int32_t sample32bit;
	int64_t index;
	char	*sample;

	index = (i * W_BLOCK_ALIGN(w)) + (j * (W_BITS_PER_SAMPLE(w) / 8)); 
	if (W_BITS_PER_SAMPLE(w) == 8)
	{
		if (a > 127)
			sample8bit = 127;
		else if (a < -128)
			sample8bit = -128;
		else
			sample8bit = a;
		toLittleEndian(1, (void *)&sample8bit);
		sample = (char*)&sample8bit;
		W_DATA(w)[index] = sample[0];
	}
	else if (W_BITS_PER_SAMPLE(w) == 16)
	{
		if (a > 32767)
			sample16bit = 32767;
		else if (a < -32768)
			sample16bit = -32768;
		else
			sample16bit = a;
		toLittleEndian(2, (void *)&sample16bit);
		sample = (char*)&sample16bit;
		W_DATA(w)[index] = sample[0];
		W_DATA(w)[index + 1] = sample[1];
	}
	else if (W_BITS_PER_SAMPLE(w) == 24)
	{
		if (a > 8388607)
			sample32bit = 8388607;
		else if (a < -8388608)
			sample32bit = -8388608;
		else
			sample32bit = a;
		toLittleEndian(3, (void *)&sample32bit);
		sample = (char*)&sample32bit;
		W_DATA(w)[index] = sample[0];
		W_DATA(w)[index + 1] = sample[1];
		W_DATA(w)[index + 2] = sample[2];
	}
}
