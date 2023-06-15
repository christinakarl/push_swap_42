/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 15:04:19 by ckarl             #+#    #+#             */
/*   Updated: 2023/05/06 15:04:21 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//put the final list in right order
void	right_order(t_stack **a)
{
	int	find_pos;

	find_pos = find_position(*a, 0);
	if (find_pos > (list_size(*a) / 2))
		rep_act1(a, rra, (list_size(*a) - find_pos));
	else if (find_pos <= (list_size(*a) / 2))
		rep_act1(a, ra, find_pos);
}

//check if list is sorted in ascending order
int	check_order(t_stack *list)
{
	while (list->next)
	{
		if (list->next->index < list->index)
			return (1);
		else
			list = list->next;
	}
	return (0);
}

//check if list is sorted in descending order
int	check_reverse_order(t_stack *list)
{
	while (list->next)
	{
		if (list->next->index > list->index)
			return (1);
		else
			list = list->next;
	}
	return (0);
}
