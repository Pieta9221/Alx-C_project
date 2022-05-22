#include "main.h"

/**
 * convert - conveter function, a clone of itoa.
 * @num: number.
 * @base: base.
 * @flags: arguments flags.
 * @params: parameter struct.
 *
 * Return: string.
 */
char *convert(long int num, int base, int flags, params_t *params)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = num;
	(void)params;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';

	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do {
		*--ptr = aray[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
 * unsign_p - prints unsined integer numbers.
 * @ap: argument pointer.
 * @params: the parameters struct.
 *
 * Return: bytes printed.
 */
int unsign_p(va_list ap, params_t *params)
{
	unsigned long l;

	if (params->l_mod)
		l = (unsigned long)va_arg(ap, unsigned long);
	else if (params->h_mod)
		l = (unsigned short int)va_arg(ap, unsigned int);
	else
		l = (unsigned int)va_arg(ap, unsigned int);
	params->unsign = 1;
	return (print_num(convert(1, 10, CONVERT_UNSIGNED, params), params));
}


/**
 * address - prints address.
 * @ap: argment pointer.
 * @params: the parameters struct 
 *
 * Return: bytes printed.
 */
int address(va_list ap, params_t *params)
{
	unsigned long int n = va_arg(ap, unsigned long int);
	char *str;

	if (!n)
		return (_puts("(nil)"));

	str = convert(n, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, params);
	*--str = 'x';
	*--str = '0';
	return (print_num(str, params));
}

