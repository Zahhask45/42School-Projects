/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   utils.c                                                    _             */
/*                                                            _ \'-_,#        */
/*   By: jodos-sa <jodos-sa@student.42porto.com>             _\'--','`|       */
/*                                                           \`---`  /        */
/*   Created: 2025/12/03 18:18:32 by jodos-sa                 `----'`         */
/*   Updated: 2026/01/04 14:49:48 by jodos-sa                                 */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_abs(long num)
{
	if (num >= 0)
		return (num);
	else
		return (num * -1);
}

int	ft_unum_len(size_t num, int base)
{
	int	len;

	len = 0;
	if (num <= 0)
		len++;
	while (num != 0)
	{
		num /= base;
		len++;
	}
	return (len);
}

int	ft_num_len(ssize_t num, int base)
{
	int	len;

	len = 0;
	if (num <= 0)
		len++;
	while (num != 0)
	{
		num /= base;
		len++;
	}
	return (len);
}

void	ft_itoa_base(ssize_t num, int base, char **str)
{
	static char	buf[4545];
	int			len;
	int			pos;

	pos = 0;
	len = ft_num_len(num, base);
	if (*str == NULL)
	{
		*str = buf + 4545 + len;
		**str = 0;
		*(*str + (len)) = '\0';
		if (num < 0)
			*(*str) = '-';
		else if (num == 0)
			*(*str) = '0';
	}
	if (num == 0)
		return ;
	pos = num % base;
	*(*str + (len - 1)) = BASE[ft_abs(pos)];
	ft_itoa_base(num / base, base, str);
}

void	ft_utoa_base(size_t num, int base, char **str)
{
	static char	buf[4545];
	int			len;
	int			pos;

	pos = 0;
	len = ft_unum_len(num, base);
	if (*str == NULL)
	{
		*str = buf + 4545 + len;
		**str = 0;
		*(*str + (len)) = '\0';
		if (num == 0)
			*(*str) = '0';
	}
	if (num == 0)
		return ;
	pos = num % base;
	*(*str + (len - 1)) = BASE[ft_abs(pos)];
	ft_itoa_base(num / base, base, str);
}
