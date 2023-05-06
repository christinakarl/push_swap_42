/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 13:03:11 by ckarl             #+#    #+#             */
/*   Updated: 2022/10/27 14:20:08 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_copy(char const *str, int start, int end)
{
	char	*copy;
	int		i;

	i = 0;
	copy = (char *)malloc(sizeof(*copy) * (end - start + 2));
	if (!copy)
		return (NULL);
	while (start <= end)
		copy[i++] = str[start++];
	copy[i] = '\0';
	return (copy);
}

int	ft_set(char const s1, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == s1)
			return (1);
		i++;
	}
	return (0);
}

int	ft_end(char const *s1, char const *set)
{
	int	end;

	end = ((int)ft_strlen(s1)) - 1;
	while (end > 0 && ft_set(s1[end], set) == 1)
			end--;
	return (end);
}

int	ft_start(char const *s1, char const *set)
{
	int	start;

	start = 0;
	while (s1[start] && ft_set(s1[start], set) == 1)
		start++;
	return (start);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*new;

	new = NULL;
	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	end = ft_end(s1, set);
	start = ft_start(s1, set);
	if (start > end)
		return (ft_strdup(""));
	new = ft_copy(s1, start, end);
	return (new);
}
