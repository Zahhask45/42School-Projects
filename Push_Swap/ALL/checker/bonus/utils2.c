/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodos-sa <jodos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 14:51:17 by jodos-sa          #+#    #+#             */
/*   Updated: 2023/04/17 17:12:35 by jodos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	check_only_num(char *argv)
{
	int	i;
	int	x;

	x = 1;
	i = -1;
	if (*argv == '\0')
		return (x);
	while (argv[++i] != '\0')
	{
		if (argv[i] >= '0' && argv[i] <= '9')
			x = 0;
	}
	return (x);
}
