/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 18:01:45 by jodos-sa          #+#    #+#             */
/*   Updated: 2022/11/03 19:09:53 by jodos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t	n)
{
	size_t	l;

	l = 0;
	while (l < n)
	{
		((unsigned char *)s)[l] = c;
		l++;
	}
	return (s);
}
/*
int	main()
{
	char	str[10];
	char	str2[10];

	memset(str, '!', 5);
	ft_memset(str2, '!', 5);
	printf("Normal: %s", str);
	printf("\nMine  : %s", str2);
	return 0;
}*/
