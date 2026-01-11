/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   prepend.c                                                  _             */
/*                                                            _ \'-_,#        */
/*   By: jodos-sa <jodos-sa@student.42porto.com>             _\'--','`|       */
/*                                                           \`---`  /        */
/*   Created: 2025/12/26 16:32:08 by jodos-sa                 `----'`         */
/*   Updated: 2026/01/04 14:48:13 by jodos-sa                                 */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_prepend_middle(char **new, char **str, int zeros)
{
	int	len;

	len = ft_strlen(*str);
	if ((*str)[0] == '-' || (*str)[0] == '+' || (*str)[0] == ' ')
	{
		*str = *new - (zeros + 1);
		(*str)[0] = (*new)[0];
		ft_memset(*str + 1, '0', zeros);
		ft_memcpy(*str + 1 + zeros, *new + 1, len - 1);
		(*str)[zeros + len] = '\0';
		return (0);
	}
	if ((*str)[0] == '0' && ((*str)[1] == 'x' || (*str)[1] == 'X'))
	{
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

void	ft_prepend_zeros(char **str, t_format *fmt)
{
	char	*new;
	int		len;
	int		zeros;

	len = ft_strlen(*str);
	zeros = fmt->width - len;
	new = *str;
	if (zeros <= 0)
		return ;
	if (ft_prepend_middle(&new, str, zeros))
	{
		*str = new - zeros;
		ft_memset(*str, '0', zeros);
	}
	fmt->width = 0;
}

void	ft_prepend_sign(char **str)
{
	char	*new;

	if (*str[0] == '-')
		return ;
	new = *str;
	*str = new - 1;
	(*str)[0] = '+';
}

void	ft_prepend_hex(char **str)
{
	char	*s;

	s = *str;
	if (s[0] == '0' && s[1] == '\0')
		return ;
	*str = s - 2;
	(*str)[0] = '0';
	(*str)[1] = 'x';
}

void	ft_prepend_alternative(char **str, t_format *fmt)
{
	char	*s;

	s = *str;
	if (s[0] == '0' && s[1] == '\0')
		return ;
	if (fmt->type == 'o')
	{
		*str = s - 1;
		(*str)[0] = '0';
	}
	else
	{
		*str = s - 2;
		(*str)[0] = '0';
		(*str)[1] = 'x';
	}
}
