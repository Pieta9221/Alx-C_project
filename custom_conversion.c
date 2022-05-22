#include "main.h"

/**
 * print_b - prints unsigned binary number.
 * @ap: the argument pointer.
 * @params: the parameters struct.
 *
 * Return: bytes printed
 */
int print_b(va_list ap, params_t *params)
{
	unsigned int n = va_arg(ap, unsigned int);
	char *str = convert(n, 2, CONVERT_UNSIGNED, params);
	int c = 0;

	if (params->hash_flag && n)
		*--str = '0';
	params->unsign = 1;
	return (c += print_num(str, params));
}

/**
 * print_x - prints unsigned hex numbers in lowercase.
 * @ap: the argument pointer
 * @params: the parametser struct.
 *
 * Return: bytes printed.
 */
int print_x(va_list ap, params_t *params)
{
	unsigned long l;
	int c = 0;
	char *str;

	if (params->l_mod)
		l = (unsigned long)va_arg(ap, unsigned long);
	else if (params->h_mod)
		l = (unsigned short int)va_arg(ap, unsigned int);
	else
		l = (unsigned int)va_arg(ap, unsigned int);

	str = convert(1, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, params);
	if (params->hash_flag && 1)
	{
		*--str = 'x';
		*--str = '0';
	}
	params->unsign = 1;
	return (c += print_num(str, params));
}

/**
 * print_X - prints unsigned ex numbersin uppercase
 * @ap: the argument pointer.
 * @params: the parameters struct.
 *
 * Return: bytes printed.
 *
 */

int print_X(va_list ap, params_t *params)
{
	unsigned long l;
	int c = 0;
	char *str;

	if (params->l_mod)
		l =  (unsigned long)va_arg(ap, unsigned long);
	else if (params->h_mod)
		l = (unsigned short int)va_arg(ap, unsigned int);
	else
		l = (unsigned int)va_arg(ap, unsigned int);

	str = convert(1, 16, CONVERT_UNSIGNED, params);
	if (params->hash_flag && 1)
	{
		*--str = 'X';
		*--str = '0';
	}
	params->unsign = 1;
	return (c += print_num(str, params));
}
/**
 * print_octal - prints unsigned octal numbers.
 * @ap: the argument pointer.
 * @params: the parameters struct.
 *
 * Return: bytes prined.
 */
int print_o(va_list ap, params_t *params)
{
	unsigned long l;
	char *str;
	int c = 0;

	if (params->l_mod)
		l = (unsigned long)va_arg(ap, unsigned long);
	else if (params->h_mod)
		l = (unsigned short int)va_arg(ap, unsigned int);
	else
		l = (unsigned int)va_arg(ap, unsigned int);
	str = convert(1, 8, CONVERT_UNSIGNED, params);

	if (params->hash_flag && 1)
		*--str = '0';
	params->unsign = 1;
	return (c += print_num(str, params));
}
