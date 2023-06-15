/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 15:04:19 by ckarl             #+#    #+#             */
/*   Updated: 2023/06/15 19:10:20 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//free allocated memory
void	clear_all(char **tab, t_stack **list)
{
	clear_tab(tab);
	clear_list(list);
}

//print entire stack
void	print_stack(char c, t_stack *x)
{
	ft_printf("stack %c: ", c);
	while (x)
	{
		ft_printf("%d ", x->cont);
		x = x->next;
	}
	ft_printf("\n");
}

int	put_error(char *str)
{
	ft_putstr_fd(str, 2);
	return (0);
}

int	clear_and_error(char **tab, t_stack **x)
{
	if (tab && x)
		clear_all(tab, x);
	else if (tab)
		clear_tab(tab);
	else if (x)
		clear_list(x);
	return (put_error(ERROR));
}

int	main(int argc, char **argv)
{
	char	**tab;
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	if (ft_strchr(argv[1], ' ') != NULL)
	{
		if (argc > 2)
			return (put_error(ERROR));
		tab = ft_split(argv[1], ' ');
	}
	else
		tab = input_tab(argv, argc);
	if (check_input(tab) == 1)
		return (clear_and_error(tab, &a));
	if (new_list(&a, tab) == 1 || check_dupl(&a) == 1)
		return (clear_and_error(tab, &a));
	new_list(&b, tab);
	bubble_sort(&b);
	index_list(&a, b);
	clear_list(&b);
	direct_algo(&a, &b);
	clear_all(tab, &a);
	return (0);
}

	// print_stack('a', a);
	// print_stack('b', b);