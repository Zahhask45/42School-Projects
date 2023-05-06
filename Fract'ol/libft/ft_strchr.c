/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 12:43:47 by jodos-sa          #+#    #+#             */
/*   Updated: 2022/11/05 13:13:58 by jodos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *src, int n)
{
	while (*src != '\0' && n != *src)
		src++;
	if (n == *src)
		return ((char *)src);
	return (0);
}
/*
int	main()
{
	char	str[4] = "NICE";

	printf("NORMAL: %s", strchr(str, 'I'));
	printf("\nMINE:   %s", ft_strchr(str, 'I'));
	return 0;
}*/
