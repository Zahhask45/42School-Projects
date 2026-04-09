/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   convert.c                                                  _             */
/*                                                            _ \'-_,#        */
/*   By: jodos-sa <jodos-sa@student.42porto.com>             _\'--','`|       */
/*                                                           \`---`  /        */
/*   Created: 2026/01/04 14:28:56 by jodos-sa                 `----'`         */
/*   Updated: 2026/01/04 14:49:56 by jodos-sa                                 */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_convert_int(va_list args, t_format *fmt)
{
	if (!ft_strncmp(fmt->length, "ll", 2) || !ft_strncmp(fmt->length, "z", 1))
		return (ft_print_digit(va_arg(args, long long), 10, 0, fmt));
	else if (!ft_strncmp(fmt->length, "l", 1))
		return (ft_print_digit(va_arg(args, long), 10, 0, fmt));
	else if (!ft_strncmp(fmt->length, "hh", 2))
		return (ft_print_digit((char)va_arg(args, int), 10, 0, fmt));
	else if (!ft_strncmp(fmt->length, "h", 1))
		return (ft_print_digit((short)va_arg(args, int), 10, 0, fmt));
	else if (!ft_strncmp(fmt->length, "j", 1))
		return (ft_print_digit(va_arg(args, intmax_t), 10, 0, fmt));
	else if (!ft_strncmp(fmt->length, "t", 1))
		return (ft_print_digit(va_arg(args, ptrdiff_t), 10, 0, fmt));
	else
		return (ft_print_digit((ssize_t)va_arg(args, int), 10, 0, fmt));
}

int	ft_convert_uint(va_list args, int base, int up, t_format *fmt)
{
	if (!ft_strncmp(fmt->length, "ll", 2) || !ft_strncmp(fmt->length, "z", 1))
		return (
			ft_print_udigit(va_arg(args, ssize_t), base, up, fmt));
	else if (!ft_strncmp(fmt->length, "l", 1))
		return (
			ft_print_udigit(va_arg(args, unsigned long), base, up, fmt));
	else if (!ft_strncmp(fmt->length, "hh", 2))
		return (
			ft_print_udigit((unsigned char)va_arg(args, int), base, up, fmt));
	else if (!ft_strncmp(fmt->length, "h", 1))
		return (
			ft_print_udigit((unsigned short)va_arg(args, int), base, up, fmt));
	else if (!ft_strncmp(fmt->length, "j", 1))
		return (
			ft_print_udigit(va_arg(args, uintmax_t), base, up, fmt));
	else if (!ft_strncmp(fmt->length, "t", 1))
		return (
			ft_print_udigit(va_arg(args, ptrdiff_t), base, up, fmt));
	else
		return (
			ft_print_udigit((size_t)va_arg(args, unsigned int), base, up, fmt));
}

int	ft_print_width(t_format *fmt)
{
	int	count;

	count = 0;
	while (fmt->width > 0 || fmt->space)
	{
		if (fmt->zero)
			count += write(1, "0", 1);
		else
			count += write(1, " ", 1);
		fmt->width--;
	}
	return (count);
}

void	ft_prepend_space(char **str)
{
	char	*new;

	if ((*str)[0] == '-')
		return ;
	new = *str;
	*str = new - 1;
	(*str)[0] = ' ';
}

void	ft_to_upper(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= ('a' - 'A');
		i++;
	}
}
