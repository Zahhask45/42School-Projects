/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodos-sa <jodos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 17:44:30 by jodos-sa          #+#    #+#             */
/*   Updated: 2023/05/06 17:22:31 by jodos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	close_win(t_all *prg)
{
	mlx_destroy_image(prg->mlx, prg->img);
	mlx_destroy_window(prg->mlx, prg->win);
	mlx_destroy_display(prg->mlx);
	free(prg->mlx);
	free(prg);
	exit(EXIT_SUCCESS);
}

void	make_windows(t_all *prg)
{
	prg->mlx = mlx_init();
	prg->win = mlx_new_window(prg->mlx, WIDTH, HEIGHT, "BANANA");
	prg->img = mlx_new_image(prg->mlx, WIDTH, HEIGHT);
	prg->addr = mlx_get_data_addr(prg->img, &(prg->bits_per_pixel),
			&(prg->line_length), &(prg->endian));
	start_fractol(prg);
	which_fractol(prg);
	mlx_put_image_to_window(prg->mlx, prg->win, prg->img, 0, 0);
	print_xy(prg);
	mlx_hook(prg->win, 2, 1L << 0, keyhooks, prg);
	mlx_mouse_hook(prg->win, mousehook, prg);
	mlx_hook(prg->win, 6, 0, motion, prg);
	mlx_hook(prg->win, 17, 0, close_win, prg);
	mlx_loop(prg->mlx);
}

void	options(void)
{
	ft_putstr("||============================================================");
	ft_putstr("==================||\n");
	write(STDOUT_FILENO, _YELLOW, ft_strlen(_YELLOW));
	ft_putstr("||  For Mandelbrot:\t\t\t\t\t\t\t\t||\n");
	write(STDOUT_FILENO, _RED, ft_strlen(_RED));
	ft_putstr("||  \tExample:");
	write(STDOUT_FILENO, _GREEN, ft_strlen(_GREEN));
	ft_putstr(" ./fractol mandel\t\t\t\t\t\t||\n");
	write(STDOUT_FILENO, _YELLOW, ft_strlen(_YELLOW));
	ft_putstr("||  For Julia:\t\t\t\t\t\t\t\t\t||\n");
	write(STDOUT_FILENO, _RED, ft_strlen(_RED));
	ft_putstr("||  \tExample: ");
	write(STDOUT_FILENO, _GREEN, ft_strlen(_GREEN));
	ft_putstr("./fractol julia [value1] [value2] or just ./fractol julia\t||\n");
	write(STDOUT_FILENO, _YELLOW, ft_strlen(_YELLOW));
	ft_putstr("||  For Tricorn:\t\t\t\t\t\t\t\t||\n");
	write(STDOUT_FILENO, _RED, ft_strlen(_RED));
	ft_putstr("||  \tExample: ");
	write(STDOUT_FILENO, _GREEN, ft_strlen(_GREEN));
	ft_putstr("./fractol tricorn\t\t\t\t\t\t||\n");
	write(STDOUT_FILENO, _END, ft_strlen(_END));
	ft_putstr("||============================================================");
	ft_putstr("==================||\n");
	exit(EXIT_FAILURE);
}

void	errorcheck(char *str, t_all *prg, int argc)
{
	if ((!(ft_strcmp(str, "mandel") == 0)) && (!(ft_strcmp(str, "julia") == 0))
		&& (!(ft_strcmp(str, "tricorn") == 0)))
	{
		free(prg);
		options();
	}
	if ((!ft_strcmp(str, "mandel") && argc > 2) || (!ft_strcmp(str, "tricorn")
			&& argc > 2) || (!ft_strcmp(str, "julia") && (argc != 2 && argc != 4)))
	{
		free(prg);
		options();
	}
	if (ft_strcmp(str, "julia") == 0)
		prg->fractol = 1;
	if (ft_strcmp(str, "mandel") == 0)
		prg->fractol = 2;
	if (ft_strcmp(str, "tricorn") == 0)
		prg->fractol = 3;
}

int	main(int argc, char **argv)
{
	t_all	*prg;

	if (argc < 2)
		options();
	prg = (t_all *)ft_memalloc(sizeof(t_all));
	if (!prg)
	{
		free(prg);
		return (1);
	}
	errorcheck(argv[1], prg, argc);
	prg->color = 1;
	prg->cre = 9999;
	prg->cim = 9999;
	if (argc > 2 && !ft_strcmp(argv[1], "julia"))
	{
		if (does_have_letters(argv[2]) || does_have_letters(argv[3]))
		{
			free(prg);
			options();
		}
		prg->cre = ft_atof(argv[2]);
		prg->cim = ft_atof(argv[3]);
	}
	make_windows(prg);
}
