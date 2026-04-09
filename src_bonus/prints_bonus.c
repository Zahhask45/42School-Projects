/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   prints.c                                                   _             */
/*                                                            _ \'-_,#        */
/*   By: jodos-sa <jodos-sa@student.42porto.com>             _\'--','`|       */
/*                                                           \`---`  /        */
/*   Created: 2025/12/03 18:18:32 by jodos-sa                 `----'`         */
/*   Updated: 2026/01/04 14:48:51 by jodos-sa                                 */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_print_char(int c, t_format *fmt)
{
	int			count;

	count = 0;
	fmt->width -= 1;
	if (fmt->minus)
	{
		count += ft_abs(write(1, &c, 1));
		count += ft_print_width(fmt);
	}
	else
	{
		count += ft_print_width(fmt);
		count += ft_abs(write(1, &c, 1));
	}
	return (count);
}

int	ft_print_str(char *s, t_format *fmt)
{
	static char	copy[4545];
	int			count;
	int			i;

	count = 0;
	i = 0;
	if (!s && (fmt->precision == -1 || fmt->precision > 5))
		s = "(null)";
	if (!s)
		s = "";
	if (fmt->type == 's')
	{
		ft_memcpy(copy + 4545, s, ft_strlen(s) + 1);
		s = copy + 4545;
	}
	handle_flags(fmt, &s);
	while (s[i])
	{
		count += write(1, &s[i], 1);
		i++;
	}
	return (count);
}

int	ft_print_udigit(size_t n, int base, int is_upper, t_format *fmt)
{
	char	*str;
	int		count;

	str = NULL;
	count = 0;
	ft_utoa_base(n, base, &str);
	if (is_upper)
		ft_to_upper(str);
	if (n == 0)
		fmt->hash = 0;
	count += ft_print_str(str, fmt);
	return (count);
}

int	ft_print_digit(ssize_t n, int base, int is_upper, t_format *fmt)
{
	char	*str;
	int		count;

	str = NULL;
	count = 0;
	ft_itoa_base(n, base, &str);
	if (is_upper)
		ft_to_upper(str);
	if (n == 0)
		fmt->hash = 0;
	count += ft_print_str(str, fmt);
	return (count);
}

int	ft_print_ptr(void *p, t_format *fmt)
{
	uintptr_t	ptr;
	char		*str;
	int			count;

	ptr = (uintptr_t)p;
	str = NULL;
	count = 0;
	if (!ptr)
		return (ft_print_str("(nil)", fmt));
	ft_itoa_base(ptr, 16, &str);
	ft_prepend_hex(&str);
	count += ft_print_str(str, fmt);
	return (count);
}
