#include "wave.h"
#include "project.h"

bool	check_header(wave_t *w)
{
	if (strncmp(w->header->riff, "RIFF", 4))
		return false;
	if (strncmp(w->header->wave, "WAVE", 4))
		return false;
	if (strncmp(w->header->fmt_str, "fmt ", 4))
		return false;
	if (strncmp(w->header->data, "data", 4))
		return false;
	if (W_FMT_TYPE(w) != 1)
		return false;
	if (W_CHANNELS(w) > 6)
		return false;
	if (W_BITS_PER_SAMPLE(w) != 8 && W_BITS_PER_SAMPLE(w) != 16 && W_BITS_PER_SAMPLE(w) != 24)
		return false;
	return true;
}

wave_t		*wave_load(const char* fname)
{
	wave_t	*wave;
	FILE	*ptr;
	char	*filename;
	char	path[1024];
	int	read;
	
	read = 0;
	if (strncmp(fname + (strlen(fname) - 4), ".wav", 4))
	{
		fprintf(stderr,"not a .wav file.\n");	
		return NULL;
	}
	if (!(filename = (char *)malloc(sizeof(char) * 1024)))
	{
		fprintf(stderr,"malloc error in wave_load.\n");
		return NULL;
	}
	if (getcwd(path, 1024) != 0)
	{
		strcpy(filename, path);
		strcat(filename, "/");
		strcat(filename, fname);
	}
	if (!(ptr = fopen(filename, "r")))
	{
		fprintf(stderr,"open error in wave_load.\n");
		if (filename != NULL)
			free(filename);
		return NULL;
	}
	if (filename != NULL)
		free(filename);
	if (!(wave = (wave_t *)malloc(sizeof(wave_t))))
	{	
		fprintf(stderr,"malloc error in wave_load for wave_t.\n");
		fclose(ptr);
		return NULL;
	}
	wave->header = NULL;
	wave->data = NULL;
	if (!(wave->header = (wave_header *)malloc(sizeof(wave_header))))
	{
		fprintf(stderr,"malloc error in wave_load for header.\n");
		wave_delete(&wave);
		fclose(ptr);
		return NULL;
	}
	if (!(read = fread(wave->header, sizeof(wave_header), 1, ptr)))
	{
		fprintf(stderr,"read error in wave_load.\n");
		fclose(ptr);
		return NULL;
	}
	if (!check_header(wave))
	{	
		fprintf(stderr,"Bad formated WAVE header.\n");
		wave_delete(&wave);
		fclose(ptr);
		return NULL;
	}
	if (!(wave->data = (char *)malloc(sizeof(char) * (W_DATA_SIZE(wave) + 1))))
	{
		fprintf(stderr,"malloc error in wave_load.\n");
		wave_delete(&wave);
		fclose(ptr);
		return NULL;
	}
	if (!(read = fread(wave->data, sizeof(char), W_DATA_SIZE(wave), ptr)))
	{
		fprintf(stderr,"read error in wave_load data. read = %d\n",read);
		fclose(ptr);
		return NULL;
	}
	fclose(ptr);
	return (wave);
}
