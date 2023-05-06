/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whichfractol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodos-sa <jodos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:24:13 by jodos-sa          #+#    #+#             */
/*   Updated: 2023/05/03 14:38:49 by jodos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	which_fractol(t_all *prg)
{
	if (prg->fractol == 1)
		julia(prg);
	if (prg->fractol == 2)
		mandel(prg);
	if (prg->fractol == 3)
		something(prg);
}

void	zoomin(int x, int y, t_all *prg)
{
	x -= WIDTH / 2;
	y -= HEIGHT / 2;
	prg->x2 = ((prg->x - x) - WIDTH) / ((double)HEIGHT * 2);
	prg->y2 = ((prg->y - y) - HEIGHT) / (((double)WIDTH * 2) + y);
	prg->zoom *= pow(1.001, 70);
	prg->movex -= prg->x2;
	prg->movey -= prg->y2;
}

void	zoomout(int x, int y, t_all *prg)
{
	x -= WIDTH / 2;
	y -= HEIGHT / 2;
	prg->x2 = ((prg->x - x) - WIDTH) / ((double)HEIGHT * 2);
	prg->y2 = ((prg->y - y) - HEIGHT) / (((double)WIDTH * 2) + y);
	prg->zoom /= pow(1.001, 70);
	prg->movex -= prg->x2;
	prg->movey -= prg->y2;
}

int	motion(int x, int y, t_all *prg)
{
	if (x > 0 && y > 0 && x < WIDTH && y < HEIGHT)
	{
		if ((prg->fractol == 1 || prg->fractol == 6) && prg->movemouse == 1)
		{
			prg->clickx = x;
			prg->clicky = y;
			prg->cre = ((prg->clickx - prg->x) - WIDTH)
				/ (((double)HEIGHT * 2) + prg->y);
			prg->cim = ((prg->clicky + prg->y) - HEIGHT)
				/ ((double)HEIGHT * 2);
			which_fractol(prg);
			mlx_put_image_to_window(prg->mlx, prg->win, prg->img, 0, 0);
			print_xy(prg);
		}
	}
	return (0);
}
