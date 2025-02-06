/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjooris <tjooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 13:46:01 by tjooris           #+#    #+#             */
/*   Updated: 2025/02/06 13:46:01 by tjooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "push_swap.h"

void	rra(t_node **stack, int a)
{
	t_node	*node;

	node = *stack;
	if (!node)
		return ;
	if (node->next == *stack && node->prev == *stack)
		return ;
	if (node->next->next == *stack && node->prev == *stack)
	{
		sa(stack, 0);
		return ;
	}
	*stack = (*stack)->prev;
	if (a)
		write(1, "rra\n", 4);
}

void	rrb(t_node **stack, int a)
{
	t_node	*node;

	node = *stack;
	if (!node)
		return ;
	if (node->next == *stack && node->prev == *stack)
		return ;
	if (node->next->next == *stack && node->prev == *stack)
	{
		sa(stack, 0);
		return ;
	}
	*stack = (*stack)->prev;
	if (a)
		write(1, "rrb\n", 4);
}

void	rrr(t_node **stack_a, t_node **stack_b)
{
	rra(stack_a, 0);
	rrb(stack_b, 0);
	write (1, "rrr\n", 4);
}
