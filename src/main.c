/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjooris <tjooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 03:40:56 by tjooris           #+#    #+#             */
/*   Updated: 2025/02/12 14:47:30 by tjooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	order_checker(t_node *stack)
{
	t_node	*current;

	current = stack;
	while (current->next != stack)
	{
		if (current->nb > current->next->nb)
			return ;
		current = current->next;
	}
	exit(EXIT_SUCCESS);
}

void	moves_init(t_node **stack_a, int n)
{
	t_node	*node;

	node = *stack_a;
	while (node->next != *stack_a)
	{
		node->sa = n;
		node->sb = n;
		node->ra = n;
		node->rb = n;
		node->rra = n;
		node->rrb = n;
		node->move = n;
		node = node->next;
	}
	node->sa = n;
	node->sb = n;
	node->ra = n;
	node->rb = n;
	node->rra = n;
	node->rrb = n;
	node->move = n;
}

int	main(int ac, char **av)
{
	char	**array;
	t_node	*stack_a;
	t_node	*stack_b;

	if (av[1])
		if (!av[1][0])
			error();
	stack_a = NULL;
	array = NULL;
	array = args_handler(&ac, av);
	stack_a = stack_a_init(stack_a, array);
	ft_free_array(array);
	order_checker(stack_a);
	stack_b = NULL;
	if (ac <= 3)
		sort_three_numbers(&stack_a);
	else if (ac <= 5)
		sort_five_numbers(&stack_a, &stack_b);
	else
	{
		index_init(stack_a);
		big_sort(&stack_a, &stack_b);
	}
	ft_free_stack(&stack_a, stack_size(stack_a));
}
