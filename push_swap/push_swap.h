/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 15:04:13 by ckarl             #+#    #+#             */
/*   Updated: 2023/05/06 15:04:15 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_stack
{
	int				cont;
	int				index;
	struct s_stack	*to;
	int				pos;
	int				mov;
	int				len;
	int				med;
	struct s_stack	*prev;
	struct s_stack	*next;

}	t_stack;

int				check_input(char **tab);
char			**input_tab(char **argv, int argc);
void			clear_tab(char **tab);
int				check_dupl(t_stack **head);
int				new_list(t_stack **list, char **tab);
long long int	ft_longatoi(const char *str);
void			list_append(t_stack **lst, int content);
void			bubble_sort(t_stack **head);
void			content_swap(t_stack *one, t_stack *two);
t_stack			*get_node(t_stack *head, int index);
void			clear_all(char **tab, t_stack **list);
void			clear_list(t_stack **list);
void			clear_tab(char **tab);
void			index_list(t_stack **list, t_stack *index);
t_stack			*last_node(t_stack *lst);
t_stack			*first_node(t_stack *lst);
int				list_size(t_stack *lst);
t_stack			*node_swap(t_stack *one, t_stack *two);
t_stack			*node_rotate(t_stack *rot);
void			node_push(t_stack **push, t_stack **to);
void			sa(t_stack **a);
void			sb(t_stack **b);
void			ss(t_stack **a, t_stack **b);
void			ra(t_stack **a);
void			rb(t_stack **b);
void			rr(t_stack **a, t_stack **b);
void			rra(t_stack **a);
void			rrb(t_stack **b);
void			rrr(t_stack **a, t_stack **b);
void			pb(t_stack **a, t_stack **b);
void			pa(t_stack **a, t_stack **b);
int				check_order(t_stack *list);
int				check_reverse_order(t_stack *list);
void			direct_algo(t_stack **a, t_stack **b);
void			algo_three(t_stack **a);
void			algo_five(t_stack **a, t_stack **b);
void			algo_more(t_stack **a, t_stack **b);
int				find_position(t_stack *list, int find);
void			set_tp(t_stack **a, t_stack **b);
void			set_move(t_stack *a, t_stack **b);
int				find_best_option(t_stack *b);
void			set_lm(t_stack **a, t_stack **b);
void			move_best_option(t_stack **a, t_stack **b, int place);
void			rep_act(t_stack **a, t_stack **b, void (*act)(t_stack **, t_stack **), int rep);
void			rep_act2(t_stack **x, void (*act)(t_stack **), int rep);
int				nbr_rot(int x, int y);



#endif
