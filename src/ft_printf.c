/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_printf.c                                                _             */
/*                                                            _ \'-_,#        */
/*   By: jodos-sa <jodos-sa@student.42porto.com>             _\'--','`|       */
/*                                                           \`---`  /        */
/*   Created: 2025/12/03 18:18:25 by jodos-sa                 `----'`         */
/*   Updated: 2026/01/04 14:35:25 by jodos-sa                                 */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_length(const char **format, t_format *fmt)
{
	if (!ft_strncmp(*format, "hh", 2) || !ft_strncmp(*format, "ll", 2))
	{
		ft_strlcpy(fmt->length, *format, 2);
		*format += 2;
	}
	else if (!ft_strncmp(*format, "h", 1) || !ft_strncmp(*format, "l", 1)
		|| !ft_strncmp(*format, "j", 1) || !ft_strncmp(*format, "z", 1)
		|| !ft_strncmp(*format, "t", 1))
	{
		ft_strlcpy(fmt->length, *format, 1);
		(*format)++;
	}
}

void	check_type(const char **format, t_format *fmt)
{
	if (**format == 'c' || **format == 's' || **format == 'p' || **format == 'd'
		|| **format == 'i' || **format == 'u' || **format == 'x'
		|| **format == 'X' || **format == '%' || **format == 'o')
	{
		fmt->type = **format;
	}
}

int	print_argument(t_format *fmt, va_list args)
{
	ft_parse_wildcard(fmt, args);
	if (fmt->type == 'c')
		return (ft_print_char(va_arg(args, int), fmt));
	if (fmt->type == 's')
		return (ft_print_str(va_arg(args, char *), fmt));
	if (fmt->type == '%')
		return (write(1, "%", 1));
	if (fmt->type == 'd' || fmt->type == 'i')
		return (ft_convert_int(args, fmt));
	if (fmt->type == 'u')
		return (ft_convert_uint(args, 10, 0, fmt));
	if (fmt->type == 'x')
		return (ft_convert_uint(args, 16, 0, fmt));
	if (fmt->type == 'X')
		return (ft_convert_uint(args, 16, 1, fmt));
	if (fmt->type == 'o')
		return (ft_convert_uint(args, 8, 0, fmt));
	if (fmt->type == 'p')
		return (ft_print_ptr(va_arg(args, void *), fmt));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	int			total_len;
	t_format	fmt;

	total_len = 0;
	format_init(&fmt);
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			parse_format_specifier(&format, &fmt);
			check_valid_format(&fmt);
			total_len += print_argument(&fmt, args);
		}
		else
			total_len += write(1, format, 1);
		format++;
	}
	va_end(args);
	return (total_len);
}
