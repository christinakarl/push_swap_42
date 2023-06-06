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
	temp->content = one->content;
	one->content = two->content;
	two->content = temp->content;
	free(temp);
}

t_stack	*get_node(t_stack *head, int index)
{
	t_stack	*copy;
	int		i;

	i = 0;
	copy = head;
	while (i < index && copy != NULL)
	{
		copy = copy->next;
		i++;
	}
	return (copy);
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
			if (a->content > b->content)
				content_swap(a, b);
			x++;
		}
		i++;
	}
}

int	list_size(t_stack *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

t_stack	*last_node(t_stack *lst)
{
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_stack	*first_node(t_stack *lst)
{
	while (lst->prev)
		lst = lst->prev;
	return (lst);
}