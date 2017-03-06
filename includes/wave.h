#ifndef WAVE_H
# define WAVE_H
# include <stdint.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <math.h>
# include <time.h>

# define HEADER_SIZE 44
# define W_FILE_SIZE(x)		(x->header->overall_size)
# define W_FMT_TYPE(x)		(x->header->fmt_type)
# define W_FMT_LENGTH(x)	(x->header->fmt_length)
# define W_SAMPLE_RATE(x)	(x->header->sample_rate)
# define W_BYTE_RATE(x)		(x->header->byterate)
# define W_BLOCK_ALIGN(x)	(x->header->block_align)
# define W_BITS_PER_SAMPLE(x)	(x->header->bits_per_sample)
# define W_DATA_SIZE(x)		(x->header->data_size)
# define W_CHANNELS(x)		(x->header->channels)
# define W_DATA(x)		(x->data)

// WAVE file header
typedef struct
{
	char		riff[4];						// RIFF string
	uint32_t	overall_size;					// (S) overall size of file in bytes - 8
	char		wave[4];						// WAVE string
	char		fmt_str[4];					// fmt string with trailing null char
	uint32_t	fmt_length;					// length of the format data
	uint16_t	fmt_type;					// format type. 1-PCM
	uint16_t	channels;					// (c) no.of channels
	uint32_t	sample_rate;					// (f) sampling rate (blocks per second)
	uint32_t	byterate;					// (r) SampleRate * NumChannels * BitsPerSample/8
	uint16_t	block_align;					// (b) NumChannels * BitsPerSample/8
	uint16_t	bits_per_sample;				// (p) bits per sample, 8- 8bits, 16- 16 bits etc
	char		data[4];						// DATA string
	uint32_t	data_size;					// NumSamples * NumChannels * BitsPerSample/8 - size of the next chunk that will be read
}			wave_header;

typedef struct
{
	wave_header	*header;
	char		*data;
}			wave_t;

int			isBigEndian(void);
void			reverseEndianness(const uint64_t size, void* value);
void			toBigEndian(const uint64_t size, void* value);
void			toLittleEndian(const uint64_t size, void* value);
wave_t			*wave_canal(wave_t *w, uint16_t c);
wave_t			*wave_load(const char *fname);
wave_t			*wave_new(uint32_t f, uint16_t p, uint16_t c, uint32_t B);
bool			wave_save(const char *fname, wave_t *w);
void			wave_delete(wave_t **w);
void			wave_set(wave_t *w, uint32_t i, uint16_t j, int64_t a);
int64_t			wave_get(wave_t *w, uint32_t i, uint16_t j);
void			info_wave(wave_t *w);
void			wave_reverse(wave_t *w);
void			wave_crop(wave_t *w, uint32_t start, uint32_t end);
void			wave_scale(wave_t *w, double s);
void			add_signal(wave_t *w, double (*s)(double));
bool    		check_header(wave_t *w);
#endif
