#ifndef ARGS_H
#define ARGS_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define list option_t*
#define NOOPTION ((option_t*)NULL)

typedef struct		option_s {
	const char	*keyword;
	enum {
		OptVoid,
		OptString,
		OptDouble,
		OptUI
	}		spec;
	union {
		void (*opt_void)();
		void (*opt_str)(const char*);
		void (*opt_d)(double);
		void (*opt_ui)(unsigned int,unsigned int);
	}		fct;
	struct option_s	*next;
}			option_t;

option_t		*opt_void(option_t* l, const char* kw, void (*f)());
option_t		*opt_string(option_t* l, const char* kw, void (*f)(const char*));
option_t		*opt_double(option_t* l, const char* kw, void (*f)(double));
option_t		*opt_uint(option_t* l, const char* kw, void (*f)(unsigned int,unsigned int));
void			process_arguments(option_t* l, int argc, char* *argv);

#endif
