#include "main.h"

/**
 * print_char - print chrachter
 * @ap: argument pointer
 * @params: the paramtr
 *
 * Return: number of bytes
 */
int print_char(va_list ap, params_t *params)
{
	char pad_char = ' ';
	unsigned int pad = 1, s = 0, ch = va_arg(ap, int);

	if (params->minus_flag)
		s += _putchar(ch);
	while (pad++ < params->width)
		s += _putchar(pad_char);
	if (!params->minus_flag)
		s += _putchar(ch);
	return (s);
}
/**
 * print_int: integer
 * @ap : argument pointer
 * @params: the parr
 *
 * Return : number of bytes
 */
int print_int(va_list ap, params_t *params)
{
	long l;

	if (params->l_modifier)
		l = va_arg(ap, long);
	else if (params->h_modifier)
		l = (short int)va_arg(ap, int);
	else
		l = (int)va_arg(ap, int);
	return (print_number(convert(l, 10, 0, params), params));
}
/**
 * print_string - print a string
 * @ap: argument pointer
 * @params: the parr
 *
 * Return: num of bytes
 */
int print_string(va_list ap, params_t *params)
{
	char *str = va_arg(ap, char *), pad_char = ' ';
	unsigned int pad = 0, s = 0, i = 0, j;

	(void)params;
	switch ((int)(!str))
	{
		case 1:
			str = NULL_STRING;
	}
	j = pad = _strlen(str);
	if (params->precision < pad)
		j = pad = params->precision;

	if (params->minus_flag)
	{
		if (params->precision != UINT_MAX)
			for (i = 0; i < pad; i++)
				s += _putchar(*str++);
		else
			s += _puts(str);
	}
	return (s);
}
/**
 * print_percent - print
 * @ap: argument poinet
 * @params : teh parra
 *
 * Return : num of bytes
 */
int print_percent(va_list ap, params_t *params)
{
	(void)ap;
	(void)params;
	return (_putchar('%'));
}
/**
 * print_S - custom format
 * @ap: point
 * @params: the paramtr
 *
 * Return: number of bytes
 */
int print_S(va_list ap, params_t *params)
{
	char *str = va_arg(ap, char *);
	char *hex;
	int s = 0;

	if ((int)(!str))
		return (_puts(NULL_STRING));
	for (; *str; str++)
	{
		if ((*str > 0 && *str < 32) || *str >= 127)
		{
			s += _putchar('\\');
			s += _putchar('X');
			hex = convert(*str, 16, 0, params);
			if (!hex[1])
				s += _putchar('0');
			s += _puts(hex);
		}
		else
		{
			s += _putchar(*str);
		}
	}
	return (s);
}
