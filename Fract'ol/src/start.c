/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodos-sa <jodos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:14:45 by jodos-sa          #+#    #+#             */
/*   Updated: 2023/05/01 16:14:50 by jodos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	start_julia(t_all *prg)
{
	prg->zoom = 1;
	prg->movex = 0;
	prg->movey = 0;
	prg->maxinter = 100;
	if (prg->cre == 9999 && prg->cim == 9999)
	{
		prg->cre = -0.7;
		prg->cim = 0.27015;
	}
}

void	start_mandel(t_all *prg)
{
	prg->zoom = 1;
	prg->movex = 0;
	prg->movey = 0;
	prg->maxinter = 100;
}

void	start_fractol(t_all *prg)
{
	if (prg->fractol == 1)
		start_julia(prg);
	if (prg->fractol == 2)
		start_mandel(prg);
	if (prg->fractol == 3)
		start_mandel(prg);
}
