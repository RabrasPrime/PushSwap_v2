/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjooris <tjooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 03:41:00 by tjooris           #+#    #+#             */
/*   Updated: 2025/02/12 14:47:42 by tjooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

int	is_valid_number(char *nb, int *sign)
{
	int	i;

	i = 0;
	*sign = 1;
	if (nb[i] == '-' || nb[i] == '+')
	{
		if (nb[i] == '-')
			*sign = -1;
		i++;
	}
	if (!nb[i] || !(nb[i] >= '0' && nb[i] <= '9'))
		return (0);
	return (i);
}

int	is_integer(char *nb)
{
	int			i;
	int			sign;
	long long	result;

	if (!nb || !*nb)
		return (0);
	i = is_valid_number(nb, &sign);
	if (i == 0 && (nb[i] < '0' && nb[i] > '9'))
		return (0);
	result = 0;
	while (nb[i] >= '0' && nb[i] <= '9')
	{
		result = result * 10 + (nb[i] - '0');
		if ((sign == 1 && result > INT_MAX)
			|| (sign == -1 && - result < INT_MIN))
			return (0);
		i++;
	}
	return (nb[i] == '\0');
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

	if (!is_integer(array[0]))
		ft_free_array_error(array);
	stack = create_node(ft_atoi(array[0]));
	if (!stack)
		return (NULL);
	stack->next = stack;
	stack->prev = stack;
	i = 1;
	while (array[i])
	{
		if (!is_integer(array[i]))
			ft_free_stack_and_array_error(&stack, array);
		pile_down(&stack, create_node(ft_atoi(array[i++])));
		if (!stack)
		{
			ft_free_array(array);
			error();
		}
	}
	return (stack);
}
