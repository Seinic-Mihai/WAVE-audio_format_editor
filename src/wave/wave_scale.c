#include "wave.h"

void	wave_scale(wave_t *w, double s)
{	
	W_SAMPLE_RATE(w) *= s;
	W_BYTE_RATE(w) = W_SAMPLE_RATE(w) * W_BLOCK_ALIGN(w);
}
