/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 15:04:19 by ckarl             #+#    #+#             */
/*   Updated: 2023/05/06 15:04:21 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	content_swap(t_stack *one, t_stack *two)
{
	t_stack	*temp;

	temp = (t_stack *)malloc(sizeof(t_stack));
	if (!temp)
		return ;
	temp->cont = one->cont;
	one->cont = two->cont;
	two->cont = temp->cont;
	free(temp);
}

void	bubble_sort(t_stack **head)
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
			if (a->cont > b->cont)
				content_swap(a, b);
			x++;
		}
		i++;
	}
}
