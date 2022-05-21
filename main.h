#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdarg.h>
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <unistd.h>

#define OUTPT_BUFF_SIZE 1024
#define BUF_F -1

#define FIELD_BUF_WIDTH 50

#define NULL_LINE "(null)"

#define PARAMETERS {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

#define LOWERCASE_CONV 1
#define UNSIGNED_CONV 2

/**
 * struct params - parameters for struct
 *
 * @unsign: flag if unsigned value
 *
 * @add_flag: on if add_flag is specofied.
 * @null_flag: on if flag is specified.
 * @not_flag: on if _flag specified.
 * @hash_flag: on if _flag specified.
 * @empty_flag: on if hash_flag specified.
 *
 * @width: field width.
 * @precise: field precision.
 *
 * @h_mod: on if h_mod is specifed.
 * @l_mod: on if i_mmod is specifeid.
 *
 */

typrdef struct params
{
	unsigned int unsign : 1;

	unsigned int add_flag : 1;
	unsigned int null_flag : 1;
	unsigned int not_flag : 1;
	unsigned int hash_flag : 1;
	unsigned int empty_flag : 1;

	unsigned int width;
	unsigned int precise;

	unsigned int h_mod : 1;
	unsigned int l_mod : 1;
} params_t;

/**
 * struct spec - struct specifier
 *
 * @spec: format .
 * @f: function associated.
 */
typedef struct spec
{
	char *spec;
	int (*f)(va_list, params_t *);
} spec_t;

/* put.c */
int _puts(char *str);
int _putchar(int c);

/*functions_p.c module */
int print_c(va_list ap, params_t *params);
int print_i(va_list ap, params_t *params);
int print_s(va_list ap, params_t *params);
int print_p(va_list ap, params_t *params);
int print_S(va_list ap, params_t *params);

/* number module */
char *conversion(long int num, int base, int flags, params_t *params);
int unsign_p(va_list ap, params_t *params);
int address(va_list ap, params_t *params);

/*specifier module */
int (*get_spec(char *s))(va_list ap, params_t *params);
int get_function(char *s, va_list ap, params_t *params);
int get_flag(char *s, params_t *params);
char *get_width(char *s, params_t *params, va_list ap);
int get_mod(char *s, params_t *params);

/* convert to number module */
int print_x(va_list ap, params_t *params);
int print_X(va_list ap, params_t *params);
int print_b(va_list ap, params_t *params);
int print_o(va_list ap, params_t *params);

/* simple print module */
int print_to_fro(char *start, char *stop, char *except);
int print_reverse(va_list ap, params_t *params);
int print_rot13(va_list ap, params_t *params);

/* print number module */
int _isdigit(int c);
int _strlen(char *s);
int print_num(char *str, params_t *params);
int print_num_right(char *str, params_t *params);
int print_num_left(char *str, params_t *params);

/* parameters moduke */
void init_params(params_t *params, va_list ap);

/*field string module */
char *precision(char *p, params_t *params, va_list ap);

/* printf function */
int _printf(const char *format, ...);

#endif


