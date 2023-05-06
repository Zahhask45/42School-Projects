/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodos-sa <jodos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 15:56:43 by jodos-sa          #+#    #+#             */
/*   Updated: 2023/04/30 16:19:55 by jodos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(char *str)
{
	int	rest;
	int	i;
	int	p_n;

	i = 0;
	rest = 0;
	p_n = 1;
	while (str[i] && ((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
		i++;
	if (str[i] && (str[i] == '+' || str[i] == '-'))
	{
		if (str[i] == '-')
			p_n *= -1;
		i++;
	}
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		rest = (str[i] - '0') + (rest * 10);
		i++;
	}
	return (rest * p_n);
}
/*
int	main()
{
	int	n;
	printf("NORMAL: %d", atoi("-126ab12"));
	printf("\nMINE:   %d", ft_atoi("-126ab12"));
	return 0;
}
*/
