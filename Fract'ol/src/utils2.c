/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodos-sa <jodos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 16:37:27 by jodos-sa          #+#    #+#             */
/*   Updated: 2023/05/04 14:36:06 by jodos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	free_all(t_all *prg)
{
	mlx_destroy_image(prg->mlx, prg->img);
	mlx_destroy_window(prg->mlx, prg->win);
	mlx_destroy_display(prg->mlx);
	free(prg->mlx);
	free(prg);
	exit(EXIT_SUCCESS);
}

int	does_have_letters(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isalpha(str[i]))
			return (EXIT_FAILURE);
		i++;
	}
	return (0);
}
