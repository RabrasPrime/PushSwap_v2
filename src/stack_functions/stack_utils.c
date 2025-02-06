/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjooris <tjooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 03:41:00 by tjooris           #+#    #+#             */
/*   Updated: 2025/02/06 11:52:39 by tjooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

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
