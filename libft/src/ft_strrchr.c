/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 13:14:16 by jodos-sa          #+#    #+#             */
/*   Updated: 2022/11/05 13:19:29 by jodos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *src, int n)
{
	int			i;

	i = ft_strlen(src);
	if (n == '\0')
		return ((char *)src + i);
	while (i >= 0)
	{
		if (src[i] == n)
			return ((char *)src + i);
		i--;
	}
	return (0);
}
