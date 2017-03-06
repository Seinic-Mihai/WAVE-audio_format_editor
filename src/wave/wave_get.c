#include "wave.h"

int64_t wave_get(wave_t *w, uint32_t i, uint16_t j)
{
	int64_t	index;
	int64_t ret;
	index =  (i * W_BLOCK_ALIGN(w)) + (j * (W_BITS_PER_SAMPLE(w) / 8));
	ret = (int64_t)(W_DATA(w)[index]);
	toLittleEndian(W_BITS_PER_SAMPLE(w)/8, (void*)&ret);
	return(ret);
}
