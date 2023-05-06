/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:38:30 by ckarl             #+#    #+#             */
/*   Updated: 2022/10/27 17:12:36 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if (str1[i] - str2[i] > 0)
			return (1);
		else if (str1[i] - str2[i] < 0)
			return (-1);
		i++;
	}
	return (0);
}
