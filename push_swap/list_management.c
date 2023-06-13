/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 15:04:19 by ckarl             #+#    #+#             */
/*   Updated: 2023/05/06 15:04:21 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long int	ft_longatoi(const char *str)
{
	int	i;
	long long int	sign;
	long long int	result;

	result = 0;
	sign = 1;
	i = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= (-1);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

//append new node to list
void	list_append(t_stack **lst, int cont)
{
	t_stack	*addback;
	t_stack	*copy;
	int		i;

	i = 0;
	addback = (t_stack *)malloc(sizeof(t_stack));
	if (!addback)
		return ;
	addback->next = NULL;
	// addback->cont = (int)malloc(sizeof(int));
	// if (addback->cont == NULL)
	// 	return ;
	addback->cont = cont;

	if (*lst == NULL)
	{
		*lst = addback;
		addback->prev = NULL;
		return ;
	}
	copy = last_node(*lst);
	copy->next = addback;
	addback->prev = copy;
}

//create a new list out of parameter **tab
int	new_list(t_stack **list, char **tab)
{
	int					a;
	long long int		temp;
	int					cont;

	a = 0;
	while (tab[a])
	{
		temp = ft_longatoi(tab[a]);
		if (temp > 2147483647 || temp < -2147483648)
			return (1);
		cont = (int)temp;
		list_append(list, cont);
		a++;
	}
	return (0);
}

//fill original list with index numbers
void	index_list(t_stack **list, t_stack *index)
{
	int	i;
	int	x;
	int	len;
	t_stack	*ind_copy;
	t_stack	*list_copy;

	i = 0;
	len = list_size(*list);
	while (i < len)
	{
		x = 0;
		list_copy = get_node(*list, i);
		while (x < len)
		{
			ind_copy = get_node(index, x);
			if (ind_copy->cont == list_copy->cont)
			{
				list_copy->index = x;
				break ;
			}
			x++;
		}
		i++;
	}
}
