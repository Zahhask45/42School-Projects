/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   format.c                                                   _             */
/*                                                            _ \'-_,#        */
/*   By: jodos-sa <jodos-sa@student.42porto.com>             _\'--','`|       */
/*                                                           \`---`  /        */
/*   Created: 2025/12/22 16:32:24 by jodos-sa                 `----'`         */
/*   Updated: 2026/01/04 14:32:19 by jodos-sa                                 */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	format_init(t_format *fmt)
{
	fmt->minus = 0;
	fmt->plus = 0;
	fmt->space = 0;
	fmt->hash = 0;
	fmt->zero = 0;
	fmt->width = 0;
	fmt->wildcard = 0;
	fmt->precision = -1;
	fmt->type = 0;
	fmt->length[0] = '\0';
}

int	check_valid_format(t_format *fmt)
{
	if (fmt->space && fmt->plus)
		fmt->space = 0;
	if (fmt->minus && fmt->zero)
		fmt->zero = 0;
	if (fmt->precision && fmt->type == 'c')
		fmt->precision = -1;
	if (fmt->width < 0)
		fmt->width *= -1;
	if (fmt->zero && fmt->precision >= 0)
		fmt->zero = 0;
	return (0);
}
