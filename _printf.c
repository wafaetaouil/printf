#include "main.h"

/**
 * _printf - print
 * @format: form string
 *
 * Return: num of bytes
 */
int _printf(const char *format, ...)
{
	int s = 0;
	va_list a;
	params_t params = PARAMS_INIT;
	char *p, *st;

	va_start(a, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (p = (char *)format; *p; p++)
	{
		init_params(&params, a);
		if (*p != '%')
		{
			s += _putchar(*p);
			continue;
		}
		st = p;
		p++;
		while (get_flag(p, &params))
		{
			p++;
		}
		p = get_width(p, &params, a);
		p = get_precision(p, &params, a);
		if (get_modifier(p, &params))
			p++;
		if (!get_specifier(p))
			s += print_from_to(st, p,
					params.l_modifier || params.h_modifier ? p - 1 : 0);
		else
			s += get_print_func(p, a, &params);
	}
	_putchar(BUF_FLUSH);
	va_end(a);
	return (s);
}

