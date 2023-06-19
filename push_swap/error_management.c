/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 15:04:19 by ckarl             #+#    #+#             */
/*   Updated: 2023/06/15 19:30:41 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//check for other characters or only -- || ++
int	check_input(char **tab)
{
	int	i;
	int	j;
	int	check_digit;
	int	check_sign;

	j = -1;
	while (tab[++j])
	{
		i = -1;
		check_digit = 0;
		check_sign = 0;
		while (tab[j][++i])
		{
			if (ft_isdigit(tab[j][i]) == 1)
				check_digit++;
			if (tab[j][i] == '-' || tab[j][i] == '+')
				check_sign++;
			if (tab[j][i] != ' ' && tab[j][i] != '-' \
				&& tab[j][i] != '+' && ft_isdigit(tab[j][i]) != 1)
				return (1);
		}
		if (check_digit < 1 || check_sign > 1)
			return (1);
	}
	return (0);
}

//dup char **tab from argv
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
			if (a->cont == b->cont)
				return (1);
			x++;
		}
		i++;
	}
	return (0);
}

//free tab
void	clear_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

//free linked list
void	clear_list(t_stack **list)
{
	t_stack	*next;

	while (*list != NULL)
	{
		next = (*list)->next;
		free(*list);
		(*list) = next;
	}
	*list = NULL;
}
