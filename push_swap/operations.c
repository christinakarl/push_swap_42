/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 15:04:19 by ckarl             #+#    #+#             */
/*   Updated: 2023/05/06 15:04:21 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

t_stack	*node_rotate(t_stack *rot)
{
	t_stack	*temp;
	t_stack	*head;

	head = rot;
	if (rot->next == NULL) //in case it's last to first
	{
		temp = first_node(rot);
		rot->next = temp;
		temp->prev = rot;
		rot->prev->next = NULL;
		rot->prev = NULL;
		head = rot;
	}
	else //in case it's first to last
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

//swap first two nodes of a
void	sa(t_stack **a)
{
	if (list_size(*a) >= 2)
	{
		*a = node_swap(*a, (*a)->next);
		ft_printf("sa\n");
	}
}

//swap first two nodes of b
void	sb(t_stack **b)
{
	if (list_size(*b) >= 2)
	{
		*b = node_swap(*b, (*b)->next);
		ft_printf("sb\n");
	}
}

// //swap first two nodes of both
void	ss(t_stack **a, t_stack **b)
{
	if (list_size(*a) >= 2)
		*a = node_swap(*a, (*a)->next);
	if (list_size(*b) >= 2)
		*b = node_swap(*b, (*b)->next);
	ft_printf("ss\n");
}

//first to last for a, rotate
void	ra(t_stack **a)
{
	int		len;

	len = list_size(*a);
	if (len >= 2)
	{
		*a = node_rotate(*a);
		ft_printf("ra\n");
	}
}

//first to last for b, rotate
void	rb(t_stack **b)
{
	int		len;

	len = list_size(*b);
	if (len >= 2)
	{
		*b = node_rotate(*b);
		ft_printf("rb\n");
	}
}

//first to last both
void	rr(t_stack **a, t_stack **b)
{
	if (list_size(*a) >= 2)
		*a = node_rotate(*a);
	if (list_size(*b) >= 2)
		*b = node_rotate(*b);
	ft_printf("rr\n");
}

//last to first for a, reverse rotate rra
void	rra(t_stack **a)
{
	int		len;
	t_stack	*temp;

	*a = first_node(*a);
	len = list_size(*a);
	temp = last_node(*a);
	if (len >= 2)
	{
		*a = node_rotate(temp);
		ft_printf("rra\n");
	}
}

//last to first for b, reverse rotate rrb
void	rrb(t_stack **b)
{
	int		len;
	t_stack	*temp;

	len = list_size(*b);
	temp = last_node(*b);
	if (len >= 2)
	{
		*b = node_rotate(temp);
		ft_printf("rrb\n");
	}
}

//last to first for both rrr
void	rrr(t_stack **a, t_stack **b)
{
	t_stack	*temp_a;
	t_stack	*temp_b;

	temp_b = last_node(*b);
	temp_a = last_node(*a);
	if (list_size(*a) >= 2)
		*a = node_rotate(temp_a);
	if (list_size(*b) >= 2)
		*b = node_rotate(temp_b);
	ft_printf("rrr\n");
}

//first from a to b, a, nothing if a is empty pb
void	pb(t_stack **a, t_stack **b)
{
	if (*a != NULL)
	{
		node_push(a, b);
		ft_printf("pb\n");
	}
}

//first from b to a, a, nothin if b is empty pa
void	pa(t_stack **a, t_stack **b)
{
	if (*b != NULL)
	{
		node_push(b, a);
		ft_printf("pa\n");
	}
}