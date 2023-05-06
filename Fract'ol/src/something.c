/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   something.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodos-sa <jodos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 16:52:10 by jodos-sa          #+#    #+#             */
/*   Updated: 2023/05/04 16:35:26 by jodos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	tricorassign(t_all *prg)
{
	prg->oldima = 0;
	prg->oldre = prg->oldima;
	prg->newima = prg->oldre;
	prg->newre = prg->newima;
}

static void	tricornmagic(t_all *prg)
{
	prg->oldre = prg->newre;
	prg->oldima = prg->newima * -1;
	prg->newre = prg->oldre * prg->oldre - prg->oldima * prg->oldima
		+ prg->preal;
	prg->newima = 2 * prg->oldre * prg->oldima + prg->pima;
}

void	something(t_all *prg)
{
	prg->y = -1;
	while (++prg->y < HEIGHT)
	{
		prg->x = -1;
		while (++prg->x < WIDTH)
		{
			prg->preal = 1.5 * (prg->x - WIDTH / 2)
				/ (0.5 * prg->zoom * WIDTH) + prg->movex;
			prg->pima = (prg->y - HEIGHT / 2)
				/ (0.5 * prg->zoom * HEIGHT) + prg->movey;
			tricorassign(prg);
			prg->i = -1;
			while (++prg->i < prg->maxinter)
			{
				tricornmagic(prg);
				if ((prg->newre * prg->newre + prg->newima * prg->newima) > 4)
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
