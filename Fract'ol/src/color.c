/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodos-sa <jodos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:53:36 by jodos-sa          #+#    #+#             */
/*   Updated: 2023/05/04 16:30:05 by jodos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	putimage(t_all *prg, int x, int y, int color)
{
	int	i;

	i = (x * (prg->bits_per_pixel / 8)) + (y * prg->line_length);
	prg->addr[i] = color;
	prg->addr[++i] = color >> 8;
	prg->addr[++i] = color >> 16;
}

unsigned int	colormagic(int i, double x, double y)
{
	unsigned int	color;
	double			magic;
	double			j;
	t_color			col;

	magic = sqrt(x * x + y * y);
	j = i + 1 - (log(2) / magic) / log(2);
	col.chan[0] = (unsigned char)(sin(0.026 * j + 1) * 200 + 25);
	col.chan[1] = (unsigned char)(sin(0.023 * j + 2) * 200 + 25);
	col.chan[2] = (unsigned char)(sin(0.01 * j + 4) * 200 + 25);
	color = (col.chan[0] << 16) + (col.chan[1] << 8) + (col.chan[2] + 255);
	return (color);
}

int	print_xy(t_all *prg)
{
	char	*txt1;
	char	*txt2;
	char	*zoom;
	char	*maxinter;

	zoom = ft_itoa(prg->zoom);
	maxinter = ft_itoa(prg->maxinter);
	txt1 = ft_strjoin("Inter: ", maxinter);
	txt2 = ft_strjoin("Zoom: ", zoom);
	mlx_string_put(prg->mlx, prg->win, 10, 10, 0xFFFFFF, txt1);
	mlx_string_put(prg->mlx, prg->win, 10, 30, 0xFFFFFF, txt2);
	ft_strdel(&txt1);
	ft_strdel(&txt2);
	ft_strdel(&zoom);
	ft_strdel(&maxinter);
	return (0);
}

void	retrydraw(t_all *prg)
{
	mlx_put_image_to_window(prg->mlx, prg->win, prg->img, 0, 0);
	mlx_destroy_image(prg->mlx, prg->img);
	prg->img = mlx_new_image(prg->mlx, WIDTH, HEIGHT);
	prg->addr = mlx_get_data_addr(prg->img,
			&(prg->bits_per_pixel),
			&(prg->line_length),
			&(prg->endian));
	start_fractol(prg);
	which_fractol(prg);
	mlx_put_image_to_window(prg->mlx, prg->win, prg->img, 0, 0);
	print_xy(prg);
}
