#include "main.h"

/**
 * get_specifier - finds the format function
 * @s: the string format
 *
 * Return: number of bytes printed
 */
int (*get_specifier(char *s))(va_list ap, params_t *params)
{
	specifier_t specifiers[] = {
		{"c", print_c},
		{"d", print_i},
		{"i", print_i},
		{"s", print_s},
		{"%", print_p},
		{"b", print_b},
		{"o", print_o},
		{"u", print_unsigned},
		{"x", print_x},
		{"X", print_X},
		{"p", print_address},
		{"S", print_S},
		{"r", print_reverse},
		{"R", print_rot13},
		{NULL, NULL}
	};
	int i = 0;

	while (specifiers[i].specifier)
	{
		if (*s == specifiers[i].specifier[0])
		{
			return (specifiers[i].f);
		}
		i++;
	}
	return (NULL);
}

/**
 * get_func - finds the format func
 * @s: the string format
 * @ap: pointer to the argument
 * @params: the parameters struct
 *
 * Return: the number of bytes printed
 */
int get_func(char *s, va_list ap, params_t *params)
{
	int (*f)(va_list, params_t *) = get_specifier(s);

	if (f)
		return (f(ap, params));
	return (0);
}

/**
 * get_flag - finds the flag function
 * @s: the string format
 * @params: the parameters structure
 *
 * Return: if flag was valid
 */
int get_flag(char *s, params_t *params)
{
	int i = 0;

	switch (*s)
	{
		case '+':
			i = params->add_flag = 1;
			break;
		case ' ':
			i = params->empty_flag = 1;
			break;
		case '#':
			i = params->hash_flag = 1;
			break;
		case '-':
			i = params->not_flag = 1;
			break;
		case '0':
			i = params->null_flag = 1;
			break;
	}
	return (i);
}

/**
 * get_modifier - finds the modifier function
 * @s: the string format
 * @params: the parameters structure
 *
 * Return: if modifier was valid
 */
int get_modifier(char *s, params_t *params)
{
	int i = 0;

	switch (*s)
	{
	case 'h':
		i = params->h_mod = 1;
		break;
	case 'l':
		i = params->l_mod = 1;
		break;
	}
	return (i);
}

/**
 * get_width - gets the string format width
 * @s: the string format
 * @params: the parameters structure
 * @ap: the pointer to the argument
 *
 * Return: new pointer
 */
char *get_width(char *s, params_t *params, va_list ap)
/* should this function use char **s and modify the pointer? */
{
	int d = 0;

	if (*s == '*')
	{
		d = va_arg(ap, int);
		s++;
	}
	else
	{
		while (_isdigit(*s))
			d = d * 10 + (*s++ - '0');
	}
	params->width = d;
	return (s);
}
