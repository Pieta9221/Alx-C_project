#include "main.h"

/**
 * print_num - prints a number with options.
 * @str: the base number as a string.
 * @params: the parameter struct.
 *
 * Return: chars printed.
 */
int print_num(char *str, params_t *params)
{
	unsigned int i = _strlen(str);
	int neg = (!params->unsign && *str == '-');

	if (!params->precise && *str == '0' && !str[1])
		str = "";
	if (neg)
	{
		str++;
		i--;
	}
	if (params->precise != UINT_MAX)
		while (i++ < params->precise)
			*--str = '0';
	if (neg)
		*--str = '-';

	if (!params->not_flag)
		return (print_num_right(str, params));
	else
		return (print_num_left(str, params));
}

/**
 * _strlen - returns the length of a string.
 * @s: the string whose lengt to check
 *
 * Return: integer lenegth of dtring.
 */
int _strlen(char *s)
{
	int i = 0;

	while (*s++)
		i++;
	return (i);
}

/**
 * print_number_right - prints a number with options.
 * @str: the base number as a string.
 * @params: the parameter struct.
 *
 * Return: chars printed.
 */
int print_number_right(char *str, params_t *params)
{
	unsigned int n = 0, neg, neg2, i = _strlen(str);
	char pad_char = ' ';

	if (params->null_flag && !params->not_flag)
		pad_char = '0';
	neg = neg2 = (!params->unsign && *str == '-');
	if (neg && i < params->width && pad_char == '0' && !params->not_flag)
		str++;
	else
		neg = 0;
	if ((params->add_flag && !neg2) || (!params->add_flag && params->empty_flag && !neg2))
		i++;
	if (neg && pad_char == '0')
		n += _putchar('-');
	if (params->add_flag && !neg2 && pad_char == '0' && !params->unsign)
		n += _putchar('+');
	else if (!params->add_flag && params->empty_flag && !neg2 && !params->unsign && params->null_flag)
		n += _putchar(' ');
	while (i++ < params->width)
		n += _putchar(pad_char);
	if (neg && pad_char == ' ')
		n += _putchar('-');
	if (params->add_flag && !neg2 && pad_char == ' ' && !params->unsign)
		n += _putchar('+');
	else if (!params->add_flag && params->empty_flag && !neg2 && !params->unsign && !params->null_flag)
		n += _putchar(' ');
	n += _puts(str);
	return (n);
}

/**
 * print_number_left - prints a number with options.
 * @str: the base number as a string.
 * @params: the parameter struct.
 *
 * Return: chars printed.
 */
int print_number_left(char *str, params_t *params)
{
	unsigned int n = 0, neg, neg2, i = _strlen(str);
	char pad_char = ' ';

	if (params->null_flag && !params->not_flag)
		pad_char = '0';
	neg = neg2 = (!params->unsign && *str == '-');
	if (neg && i < params->width && pad_char == '0' && !params->not_flag)
		str++;
	else
		neg = 0;

	if (params->add_flag && !neg2 && !params->unsign)
		n += _putchar('+'), i++;
	else if (params->empty_flag && !neg2 && !params->unsign)
		n += _putchar(' '), i++;
	n += _puts(str);
	while (i++ < params->width)
		n += _putchar(pad_char);
	return (n);
}

/**
 * _isdigit - checks if carcter is digit.
 * @c: the character to check.
 *
 * Return: 1 if digit, 0 otherwise.
 */

int _isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
	
