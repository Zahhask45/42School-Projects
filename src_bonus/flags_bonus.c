/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   flags.c                                                    _             */
/*                                                            _ \'-_,#        */
/*   By: jodos-sa <jodos-sa@student.42porto.com>             _\'--','`|       */
/*                                                           \`---`  /        */
/*   Created: 2025/12/27 13:38:04 by jodos-sa                 `----'`         */
/*   Updated: 2026/01/04 14:37:34 by jodos-sa                                 */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_width(char **str, t_format *fmt)
{
	char	*new;
	int		len;
	int		spaces;

	len = ft_strlen(*str);
	spaces = fmt->width - len;
	new = *str;
	if (fmt->width > 0 && spaces > 0)
	{
		if (fmt->minus)
		{
			ft_memset(new + len, ' ', spaces);
			new[fmt->width] = '\0';
		}
		else
		{
			*str = new - spaces;
			ft_memset(*str, ' ', spaces);
		}
	}
	fmt->width = 0;
}

int	ft_prepend_middle_precision(char **new, char **str, int zeros)
{
	int	len;

	len = ft_strlen(*str);
	if ((*str)[0] == '-' || (*str)[0] == '+' || (*str)[0] == ' ')
	{
		zeros++;
		*str = *new - (zeros + 1);
		(*str)[0] = (*new)[0];
		ft_memset(*str + 1, '0', zeros);
		ft_memcpy(*str + 1 + zeros, *new + 1, len - 1);
		(*str)[zeros + len] = '\0';
		return (0);
	}
	if ((*str)[0] == '0' && ((*str)[1] == 'x' || (*str)[1] == 'X'))
	{
		zeros += 2;
		*str = *new - (zeros + 2);
		(*str)[0] = (*new)[0];
		(*str)[1] = (*new)[1];
		ft_memset(*str + 2, '0', zeros);
		ft_memcpy(*str + 2 + zeros, *new + 2, len - 2);
		(*str)[zeros + len] = '\0';
		return (0);
	}
	return (1);
}

void	ft_prepend_precision(char **str, t_format *fmt)
{
	char	*new;
	int		len;
	int		zeros;

	len = ft_strlen(*str);
	zeros = fmt->precision - len;
	new = *str;
	if (ft_prepend_middle_precision(&new, str, zeros))
	{
		*str = new - zeros;
		ft_memset(*str, '0', zeros);
	}
	fmt->precision = -1;
}

void	ft_precision(char **str, t_format *fmt)
{
	char	*new_str;

	new_str = NULL;
	if (fmt->type == 's')
	{
		(*str)[fmt->precision] = '\0';
		return ;
	}
	if (fmt->precision == 0 && ft_strlen(*str) == 1)
		(*str)[0] = '\0';
	if (fmt->precision > ft_strlen(*str))
		ft_prepend_precision(str, fmt);
}

void	handle_flags(t_format *fmt, char **str)
{
	if (fmt->hash && (fmt->type == 'x' || fmt->type == 'X' || fmt->type == 'o'))
		ft_prepend_alternative(str, fmt);
	if (fmt->precision >= 0 && fmt->type != 'c')
		ft_precision(str, fmt);
	if (fmt->plus && (fmt->type == 'd' || fmt->type == 'i'))
		ft_prepend_sign(str);
	if (fmt->space && (fmt->type == 'd' || fmt->type == 'i'))
		ft_prepend_space(str);
	if (fmt->zero && (fmt->type != 'p' && fmt->type != 's' && fmt->type != 'c'))
		ft_prepend_zeros(str, fmt);
	if (fmt->width > ft_strlen(*str))
		ft_width(str, fmt);
}
