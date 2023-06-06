/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 15:04:19 by ckarl             #+#    #+#             */
/*   Updated: 2023/05/06 15:04:21 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//check for other characters or only -- || ++ without digits
int	check_input(char **tab)
{
	int	i;
	int	j;
	int	check_digit;

	j = 0;
	check_digit = 0;
	while (tab[j])
	{
		i = 0;
		while (tab[j][i])
		{
			if (ft_isdigit(tab[j][i]) == 1)
				check_digit++;
			if (tab[j][i] == ' ' || tab[j][i] == '-' || tab[j][i] == '+' || ft_isdigit(tab[j][i]) == 1)
				i++;
			else
				return (1);
		}
		if (check_digit < 1)
			return (1);
		check_digit = 0;
		j++;
	}
	return (0);
}

//dup char **tab
char	**input_tab(char **argv, int argc)
{
	int		a;
	int		b;
	char	**tab;

	b = 0;
	a = 1;
	tab = (char **)malloc(sizeof(*tab) * argc);
	if (!tab || !argv)
		return (NULL);
	while (a < argc)
	{
		tab[b++] = ft_strdup(argv[a++]);
	}
	tab[b] = 0;
	return (tab);
}

//check for duplicates
int	check_dupl(t_stack **head)
{
	t_stack	*a;
	t_stack	*b;
	int		i;
	int		x;

	i = 0;
	while (i < list_size(*head))
	{
		a = get_node(*head, i);
		x = i + 1;
		while (x < list_size(*head))
		{
			b = get_node(*head, x);
			if (a->content == b->content)
				return (1);
			x++;
		}
		i++;
	}
	return (0);
}
