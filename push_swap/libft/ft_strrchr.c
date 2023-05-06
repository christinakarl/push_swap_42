/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 16:50:08 by ckarl             #+#    #+#             */
/*   Updated: 2022/10/27 17:07:58 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t		i;
	char		*point;
	char		b;

	b = (char)c;
	i = 0;
	point = NULL;
	while (i <= ft_strlen(s))
	{
		if (s[i] == b)
			point = (char *)&s[i];
		i++;
	}
	return (point);
}
