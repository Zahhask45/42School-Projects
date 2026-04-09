/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   parser.c                                                   _             */
/*                                                            _ \'-_,#        */
/*   By: jodos-sa <jodos-sa@student.42porto.com>             _\'--','`|       */
/*                                                           \`---`  /        */
/*   Created: 2026/01/04 14:31:59 by jodos-sa                 `----'`         */
/*   Updated: 2026/01/04 14:35:59 by jodos-sa                                 */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	parse_format_specifier(const char **format, t_format *fmt)
{
	format_init(fmt);
	flag_parser(format, fmt);
	while ((**format >= '0' && **format <= '9'))
	{
		fmt->width = fmt->width * 10 + (**format - '0');
		(*format)++;
	}
	if (**format == '.')
	{
		(*format)++;
		fmt->precision = 0;
		while (**format >= '0' && **format <= '9')
		{
			fmt->precision = fmt->precision * 10 + (**format - '0');
			(*format)++;
		}
		if (**format == '*')
		{
			fmt->wildcard += 1;
			(*format)++;
		}
	}
	check_length(format, fmt);
	check_type(format, fmt);
}

void	ft_parse_wildcard(t_format *fmt, va_list args)
{
	if (fmt->wildcard == 2 || (fmt->wildcard && fmt->precision < 0))
	{
		fmt->width = va_arg(args, int);
		if (fmt->width < 0)
		{
			fmt->width *= -1;
			fmt->minus = 1;
		}
		fmt->wildcard -= 1;
	}
	if (fmt->wildcard && fmt->precision >= 0)
	{
		fmt->precision = va_arg(args, int);
		fmt->wildcard -= 1;
	}
}

void	flag_parser(const char **format, t_format *fmt)
{
	while (**format == '-' || **format == '+' || **format == ' ' || \
**format == '#' || **format == '0' || **format == '*')
	{
		if (**format == '-')
			fmt->minus = 1;
		else if (**format == '+')
			fmt->plus = 1;
		else if (**format == ' ')
			fmt->space = 1;
		else if (**format == '#')
			fmt->hash = 1;
		else if (**format == '0')
			fmt->zero = 1;
		else if (**format == '*')
			fmt->wildcard += 1;
		(*format)++;
	}
}
