/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_best_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjooris <tjooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 03:41:39 by tjooris           #+#    #+#             */
/*   Updated: 2025/02/12 15:40:27 by tjooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "stack.h"
#include "opti.h"

void	push_one(t_node **stack_a, t_node **stack_b)
{
	t_node	*current;
	t_node	*save;
	int		max;

	max = 2147483647;
	current = *stack_b;
	while (current->next != *stack_b)
	{
		if (current->sa + current->sb + current->ra
			+ current->rb + current->rra + current->rrb < max)
		{
			max = current->sa + current->sb + current->ra
				+ current->rb + current->rra + current->rrb;
			save = current;
		}
		current = current->next;
	}
	if (current->sa + current->sb + current->ra
		+ current->rb + current->rra + current->rrb < max)
	{
		max = current->sa + current->sb + current->ra
			+ current->rb + current->rra + current->rrb;
		save = current;
	}
	do_moves(stack_a, stack_b, &save);
}

void	find_best_push(t_node **stack_a, t_node **stack_b)
{
	t_node	*current_b;
	int		i;
	int		size;

	current_b = *stack_b;
	i = 0;
	size = stack_size(*stack_b);
	while (current_b->next != *stack_b)
	{
		if (i <= size / 2)
			current_b->rb = i;
		else
			current_b->rrb = size - i;
		prepare_stack_a(stack_a, &current_b);
		i++;
		current_b = current_b->next;
	}
	if (i <= size / 2)
		current_b->rb = i;
	else
		current_b->rrb = size - i;
	prepare_stack_a(stack_a, &current_b);
	push_one(stack_a, stack_b);
}
