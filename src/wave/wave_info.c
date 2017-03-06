#include "wave.h"
#include <ncurses.h>

void    info_wave(wave_t *wave)
{
	printf("\n\n\nRIFF str = %c%c%c%c\n",wave->header->riff[0], wave->header->riff[1], wave->header->riff[2], wave->header->riff[3]);
	printf("file size (S) = %u\n",W_FILE_SIZE(wave));
	printf("WAVE str = %c%c%c%c\n",wave->header->wave[0], wave->header->wave[1], wave->header->wave[2], wave->header->wave[3]);
	printf("FMT str = %c%c%c%c\n",wave->header->fmt_str[0], wave->header->fmt_str[1], wave->header->fmt_str[2], wave->header->fmt_str[3]);
	printf("FMT LENGTH = %u\n",W_FMT_LENGTH(wave));
	printf("FMT type = %u (PCM if 1)\n",W_FMT_TYPE(wave));
	printf("CHANNELS (c) = %u\n",W_CHANNELS(wave));
	printf("SAMPLE RATE (f) = %u\n",W_SAMPLE_RATE(wave));
	printf("BYTE RATE (r) = %u\n",W_BYTE_RATE(wave));
	printf("BLOCK ALIGN (B)  = %u\n",W_BLOCK_ALIGN(wave));
	printf("BITS PER SAMPLE (p) = %u\n",W_BITS_PER_SAMPLE(wave));
	printf("DATA str = %c%c%c%c\n",wave->header->data[0], wave->header->data[1], wave->header->data[2], wave->header->data[3]);
	printf("DATA SIZE = %u\n",W_DATA_SIZE(wave));
}
