/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodos-sa <jodos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 14:32:17 by jodos-sa          #+#    #+#             */
/*   Updated: 2023/05/04 14:50:07 by jodos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	juliamagic(t_all *prg)
{
	prg->oldre = prg->newre;
	prg->oldima = prg->newima;
	prg->newre = prg->oldre * prg->oldre - prg->oldima * prg->oldima + prg->cre;
	prg->newima = 2 * prg->oldre * prg->oldima + prg->cim;
}

void	julia(t_all *prg)
{
	prg->y = -1;
	while (++prg->y < HEIGHT)
	{
		prg->x = -1;
		while (++prg->x < WIDTH)
		{
			prg->newre = 1.5 * (prg->x - WIDTH / 2)
				/ (0.5 * prg->zoom * WIDTH)
				+ prg->movex;
			prg->newima = (prg->y - HEIGHT / 2)
				/ (0.5 * prg->zoom * HEIGHT) + prg->movey;
			prg->i = -1;
			while (++prg->i < prg->maxinter)
			{
				juliamagic(prg);
				if ((prg->newre * prg->newre + prg->newima) > 4)
					break ;
			}
			if (prg->i < prg->maxinter)
				putimage(prg, prg->x, prg->y, (colormagic((prg->color * prg->i),
							prg->x, prg->y)));
			else
				putimage(prg, prg->x, prg->y, 0x000000);
		}
	}
}
