#include "main.h"

/**
 * get_specifier - find form
 * @s: string
 *
 * Return: the num of bytes
 */
int (*get_specifier(char *s))(va_list a, params_t *params)
{
	specifier_t specifiers[] = {
		{"c", print_char},
		{"d", print_int},
		{"i", print_int},
		{"s", print_string},
		{"%", print_percent},
		{"b", print_binary},
		{"o", print_octal},
		{"u", print_unsigned},
		{"x", print_hex},
		{"X", print_HEX},
		{"p", print_address},
		{"S", print_S},
		{"r", print_rev},
		{"R", print_rot13},
		{NULL, NULL}
	};
	int i = 0;

	while (specifiers[i].specifier)
	{
		if (*s == specifiers[i] .specifier[0])
		{
			return (specifiers[i] .f);
		}
		i++;
	}
	return (NULL);
}
/**
 * get_print_func - find the printf
 * @s: the format string
 * @ap: pointer
 * @params: the  param
 * Return: the number of bytes
 */
int get_print_func(char *s, va_list ap, param_t *params)
{
	int (*f)(va_list, params_t *) = get_specifier(s);

	if (f)
		return (f(ap, params));
	return (0);
}
/**
 * get_flag - find the flag
 * @s : string
 * @params: teh parametrs
 *
 * Return: valid
 */
int get_flag(char *s, params_t *params)
{
	int i = 0;

	switch (*s)
	{
		case '+':
			i = params->plus_flag = 1;
		case ' ':
			i = params->space_flag = 1;
		case '#':
			i = params->hashtag_flag = 1;
		case '-':
			i = params->minus_flag = 1;
		case '0':
			i = params->zero_flag = 1;
			break;
	}
	return (i);
}
/**
 * get_width - get teh witdh
 * @s: the form
 * @params: the param
 * @ap: the argumen
 *
 * Return: new pointer
 */
char *get_width(char *s, params_t *params, va_list ap)

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
