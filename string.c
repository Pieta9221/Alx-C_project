#include "main.h"

/**
 * get_precision - gets the precision from the string format
 * @p: the string format
 * @params: the parameters structure
 * @ap: the pointer to the argument
 *
 * Return: new pointer
 */
char *precision(char *p, params_t *params, va_list ap)
{
	int d = 0;

	if (*p != '.')
		return (p);
	p++;
	if (*p == '*')
	{
		d = va_arg(ap, int);
		p++;
	}
	else
	{
		while (_isdigit(*p))
			d = d * 10 + (*p++ - '0');
	}
	params->precise = d;
	return (p);
}
