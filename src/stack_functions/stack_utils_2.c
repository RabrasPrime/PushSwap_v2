/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjooris <tjooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 11:27:01 by tjooris           #+#    #+#             */
/*   Updated: 2025/02/12 14:47:51 by tjooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_node *stack)
{
	t_node	*list;
	int		i;

	if (!stack)
		return (0);
	if (stack->next == stack && stack->prev == stack)
		return (1);
	if (stack->next->next == stack || stack->prev == stack)
		return (2);
	list = stack;
	i = 1;
	while (list->next != stack)
	{
		list = list->next;
		i++;
	}
	return (i);
}

void	handle_duplicate_error(t_node **stack, t_node *node)
{
	ft_free_stack(stack, stack_size(*stack));
	free(node);
	*stack = NULL;
}

static int	is_duplicate(t_node *stack, int value)
{
	t_node	*head;

	head = stack;
	while (head->next != stack)
	{
		if (head->nb == value)
			return (1);
		head = head->next;
	}
	if (head->nb == value)
		return (1);
	return (0);
}

static void	insert_node(t_node **stack, t_node *node)
{
	t_node	*head;

	head = *stack;
	if ((*stack)->next == *stack && (*stack)->prev == *stack)
	{
		(*stack)->next = node;
		(*stack)->prev = node;
		node->prev = *stack;
		node->next = *stack;
	}
	else
	{
		node->prev = head->prev;
		head->prev->next = node;
		head->prev = node;
		node->next = head;
	}
}

void	pile_down(t_node **stack, t_node *node)
{
	if (!node)
	{
		ft_free_stack(stack, stack_size(*stack));
		*stack = NULL;
		return ;
	}
	if (is_duplicate(*stack, node->nb))
	{
		handle_duplicate_error(stack, node);
		return ;
	}
	insert_node(stack, node);
}
