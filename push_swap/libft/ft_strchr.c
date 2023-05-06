/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 15:08:25 by ckarl             #+#    #+#             */
/*   Updated: 2022/10/27 16:49:52 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t		i;
	char		*str;
	char		b;

	b = (char)c;
	str = (char *)s;
	i = 0;
	while (i <= ft_strlen(str))
	{
		if (str[i] == b)
			return (&str[i]);
		else
			i++;
	}
	return (NULL);
}
