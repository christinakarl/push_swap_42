/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_manipulations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 15:04:19 by ckarl             #+#    #+#             */
/*   Updated: 2023/05/06 15:04:21 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//swap two nodes with each other
t_stack	*node_swap(t_stack *one, t_stack *two)
{
	t_stack	*temp;
	t_stack	*tnext;

	temp = two->prev;
	temp->next = one;
	one->prev = temp;
	two->prev = NULL;
	tnext = one->next;
	one->next = two->next;
	two->next = tnext;
	if (one->next != NULL)
		one->next->prev = one;
	two->next->prev = two;
	return (two);
}

//first case is last to first, second first to last
t_stack	*node_rotate(t_stack *rot)
{
	t_stack	*temp;
	t_stack	*head;

	head = rot;
	if (rot->next == NULL)
	{
		temp = first_node(rot);
		rot->next = temp;
		temp->prev = rot;
		rot->prev->next = NULL;
		rot->prev = NULL;
		head = rot;
	}
	else
	{
		temp = last_node(rot);
		rot->prev = temp;
		temp->next = rot;
		head = rot->next;
		rot->next->prev = NULL;
		rot->next = NULL;
	}
	return (head);
}

//push a node from one stack to another
void	node_push(t_stack **push, t_stack **to)
{
	t_stack	*temp_p;

	temp_p = *push;
	*push = (*push)->next;
	if (*push)
		(*push)->prev = NULL;
	if (!*to)
	{
		temp_p->next = NULL;
		*to = temp_p;
	}
	else
	{
		temp_p->next = *to;
		(*to)->prev = temp_p;
		*to = (*to)->prev;
	}
}
