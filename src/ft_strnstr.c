/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 15:24:45 by jodos-sa          #+#    #+#             */
/*   Updated: 2022/11/05 15:51:28 by jodos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *huge, const char *lil, size_t l)
{
	size_t	h;
	size_t	n;

	h = 0;
	if (lil[0] == '\0')
		return ((char *)huge);
	if (l == 0)
		return (NULL);
	while (huge[h] != '\0')
	{
		n = 0;
		while (huge[h + n] == lil[n] && (h + n) < l)
		{
			if (huge[h + n] == '\0' && lil[n] == '\0')
				return ((char *)&huge[h]);
			n++;
		}
		if (lil[n] == '\0')
			return ((char *)huge + h);
		h++;
	}
	return (0);
}
/*
int	main()
{
	const char	*big = "aaa HUGE aaa";
	const char	*little = "HUGE";
	char	*ptr;

	ptr = ft_strnstr(big, little, 10);
	printf("NORMAL: %s", ptr);
	return 0;
}*/
