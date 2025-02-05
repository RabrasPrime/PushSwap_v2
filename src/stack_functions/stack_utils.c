/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjooris <tjooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 03:41:00 by tjooris           #+#    #+#             */
/*   Updated: 2025/02/05 17:29:59 by tjooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "push_swap.h"
#include "libft.h"

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

void	pile_down(t_node **stack, t_node *node)
{
	t_node	*head;

	if (!node)
	{
		ft_free_stack(stack, stack_size(*stack));
		*stack = NULL;
		return ;
	}

	head = *stack;
	while (head->next != *stack)
	{
		if (head->nb == node->nb)
		{
			ft_free_stack(stack, stack_size(*stack));
			free(node);
			*stack = NULL;
			return ;
		}
		head = head->next;
	}

	if (head->nb == node->nb)
	{
		ft_free_stack(stack, stack_size(*stack));
		free(node);
		*stack = NULL;
		return ;
	}

	if ((*stack)->next == *stack && (*stack)->prev == *stack)
	{
		(*stack)->next = node;
		(*stack)->prev = node;
		node->prev = *stack;
		node->next = *stack;
		return ;
	}

	head = *stack;
	node->prev = head->prev;
	head->prev->next = node;
	head->prev = node;
	node->next = head;
}


int	*stack_dup(int *array, t_node *stack)
{
	int		i;
	t_node	*node;

	i = 0;
	node = stack;
	array = malloc(sizeof(int) * stack_size(stack));
	while (node->next != stack)
	{
		array[i++] = node->nb;
		node = node->next;
	}
	array[i] = node->nb;
	return (array);
}

t_node	*create_node(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->nb = value;
	node->ra = 0;
	node->rb = 0;
	node->rra = 0;
	node->rrb = 0;
	return (node);
}

t_node	*stack_a_init(t_node *stack, char **array)
{
	int		i;

	stack = create_node(ft_atoi(array[0]));
	if (!stack)
		return (NULL);
	stack->next = stack;
	stack->prev = stack;
	i = 1;
	while (array[i])
	{
		pile_down(&stack, create_node(ft_atoi(array[i++])));
		if (!stack)
		{
			ft_free_array(array);
			error();
		}
	}
	return (stack);
}	
