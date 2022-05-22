include "main.h"

/**
 * print_c - prints characters.
 * @ap: argument pointer.
 * @params: parameters.
 *
 * Return: number of charactes printed.
 */
int print_c(va_list ap, params_t *params)
{
	char pad_char = ' ';
	unsigned int pad = 1, sum = 0, ch = va_arg(ap, int);

	if (params->not_flag)
		sum += _putchar(ch);
	while (pad++ < params->width)
		sum += _putchar(pad_char);
	if (!params->not_flag)
		sum += _putchar(ch);
	return (sum);
}

/**
 * print_i - ptints an integer.
 * @ap: argument pointer.
 * @params: the aprameters struct
 *
 * Return: number chars printed.
 */
int print_i(va_list ap, params_t *params)
{
	long l;

	if (params->l_mod)
		l = va_arg(ap, long);
	else if (params->h_mod)
		l = (short int)va_arg(ap, int);
	else
		l = (int)va_arg(ap, int);
	return (print_num(convert(1, 10, 0, params), params));
}

/**
 * print_s - prints strings.
 * @ap: argument pointer.
 * @params: parameters.
 *
 * Return: number of bytes printed.
 */

int print_s(va_list ap, params_t *params)
{
	char *str = va_arg(ap, char *) pad_char = ' ';
	unsigned int pad = 0, sum = 0, i =0, j;

	(void)params;
	switch ((int)(!str))
	case 1:
		str = NULL_STRING;

		j = pad = _strlen(str);
		if (params->precise < pad)
			j = pad = params->precise;

		if (params->not_flag)
		{
			if (params->precise != UINT_MAX)
				for (i = 0; i < pad; i++)
					sum += _putchar(*str++);
			else
			       	sum += _puts(str);
		}
		while (j++ < params->width)
			sum += _putchar(pad_char);
		if (!params->not_flag)
		{
			if (params->precise != UINT_MAX)
				for (i = 0; i < pad; i++)
					sum += _putchar(*str++);
			else
				sum += _puts(str);
		}
		return (sum);
}

/**
 * print_p - prints strings.
 * @ap: argument pointer.
 * @params: the parameters struct.
 *
 * Return: the number of caracters printed.
 */
int print_p(va_list ap, params_t *params)
{
	(void)ap;
	(void)params;
	return (_putchar('%'));
}

/**
 * print_S - custom format specifier.
 * @ap: argument pointer.
 * @params: the parameters struct.
 *
 * Return: number of caracters printed.
 */
int print_S(va_list ap, params_t *params)
{
	char *str = va_arg(ap, char *);
	char *hex;
	int sum = 0;

	if ((int)(!str))
		return (_puts(NULL_STRING));
	for (; *str; str++)
	{
		if ((*str > 0 && *str < 32) || *str >= 127)
		{
			sum += _putchar('\\');
			sum += _putchar('x');
			hex = convert(*str, 16, 0, params);
			if (!hex[1])
				sum += _putchar('0');
			sum += _puts(hex);
		}
		else
		{
			sum += _putchar(*str);
		}
	}
	return (sum);
}
