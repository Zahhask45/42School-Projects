/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodos-sa <jodos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 15:33:17 by jodos-sa          #+#    #+#             */
/*   Updated: 2023/05/04 14:51:15 by jodos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mousehook(int mousekey, int x, int y, t_all *prg)
{
	mlx_mouse_get_pos(prg->mlx, prg->win, &x, &y);
	if (x > 0 && y > 0 && x < WIDTH && y < HEIGHT)
	{
		if (mousekey == 4)
			zoomin(x, y, prg);
		else if (mousekey == 5)
			zoomout(x, y, prg);
		else if (mousekey == 1)
			prg->maxinter += 5;
		else if (mousekey == 3)
			prg->maxinter -= 5;
		else if (mousekey == 2)
		{
			if (prg->movemouse == 1)
				prg->movemouse = 0;
			else
				prg->movemouse = 1;
		}
		which_fractol(prg);
		mlx_put_image_to_window(prg->mlx, prg->win, prg->img, 0, 0);
		print_xy(prg);
	}
	return (0);
}

int	keyhooks3(int key, t_all *prg)
{
	if (key == 0x0020)
		retrydraw(prg);
	if (key == 18)
	{
		prg->color = 1;
		retrydraw(prg);
	}
	else if (key == 0xff54)
		prg->movey += .2 / prg->zoom;
	else if (key == 0xff52)
		prg->movey -= .2 / prg->zoom;
	else if (key == 0xff53)
		prg->movex += .2 / prg->zoom;
	else if (key == 0xff51)
		prg->movex -= .2 / prg->zoom;
	return (0);
}

int	keyhooks2(int key, t_all *prg)
{
	if (key == 0x0031)
	{
		prg->color = 0x247812;
		retrydraw(prg);
	}
	if (key == 0x0032)
	{
		prg->color = 2000;
		retrydraw(prg);
	}
	if (key == 0x0033)
	{
		prg->color += 50;
		retrydraw(prg);
	}
	if (key == 0x0034)
	{
		prg->color -= 10;
		retrydraw(prg);
	}
	return (0);
}

int	keyhooks(int key, t_all *prg)
{
	if (!(prg->win))
		return (0);
	if (key == 0xff1b)
	{
		ft_putendl_fd("Exiting", 1);
		free_all(prg);
	}
	else if (key == 0xff55)
		prg->zoom *= pow(1.001, 70);
	else if (key == 0xff56)
		prg->zoom /= pow(1.001, 70);
	else if (key == 0x003d)
		prg->maxinter += 5;
	else if (key == 0x002d)
		prg->maxinter -= 5;
	keyhooks2(key, prg);
	keyhooks3(key, prg);
	which_fractol(prg);
	mlx_put_image_to_window(prg->mlx, prg->win, prg->img, 0, 0);
	print_xy(prg);
	return (0);
}
