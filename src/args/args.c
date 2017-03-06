#include "args.h"

option_t* opt_void(option_t* l, const char* kw, void (*f)()){
	list li;
	if ((li = (list)malloc(sizeof(option_t))) != NULL)
	{
		li->keyword = kw;
		li->spec = OptVoid;
		li->fct.opt_void = f;
		li->next = l;
	}
	return li;
}

option_t* opt_string(option_t* l, const char* kw, void (*f)(const char*)){
	list li;
	if ((li = (list)malloc(sizeof(option_t))) != NULL)
	{
		li->keyword = kw;
		li->spec = OptString;
		li->fct.opt_str = f;
		li->next = l;
	}
	return li;
}

option_t* opt_double(option_t* l, const char* kw, void (*f)(double)){
	list li;
	if ((li = (list)malloc(sizeof(option_t))) != NULL)
	{
		li->keyword = kw;
		li->spec = OptDouble;
		li->fct.opt_d = f;
		li->next = l;
	}
	return li;
}

option_t* opt_uint(option_t* l, const char* kw, void (*f)(unsigned int,unsigned int)){
	list li; 
	if ((li = (list)malloc(sizeof(option_t))) != NULL)
	{
		li->keyword = kw;
		li->spec = OptUI;
		li->fct.opt_ui = f;
		li->next = l;
	}
	return li;
}
