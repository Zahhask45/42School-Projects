/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 14:21:13 by jodos-sa          #+#    #+#             */
/*   Updated: 2022/11/05 14:49:44 by jodos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *src, int c, size_t n)
{
	size_t	l;

	l = 0;
	while (l < n)
	{
		if ((unsigned char)c == ((unsigned char *)src)[l])
			return ((void *)(src + l));
		l++;
	}
	return (0);
}
