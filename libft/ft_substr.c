/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 15:25:59 by ckarl             #+#    #+#             */
/*   Updated: 2022/10/28 15:49:20 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t				i;
	size_t				j;
	char				*copy;

	j = 0;
	i = 0;
	if (!s || len == 0 || start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	copy = (char *)malloc(sizeof(*copy) * ((unsigned int)len + 1));
	if (!copy)
		return (NULL);
	while (s[i] && j < len)
	{
		if (i == start)
		{
			while (j < len && s[i])
				copy[j++] = s[i++];
		}
		else
			i++;
	}
	copy[j] = '\0';
	return (copy);
}
