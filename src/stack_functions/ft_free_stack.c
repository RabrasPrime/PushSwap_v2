/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjooris <tjooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 03:41:05 by tjooris           #+#    #+#             */
/*   Updated: 2025/03/03 08:57:16 by tjooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line.h"

void	ft_free_stack_and_array_error(t_node **stack, char **array)
{
	ft_free_array(array);
	ft_free_stack(stack, stack_size(*stack));
	ft_error();
}

void	ft_free_array_error(char **array)
{
	ft_free_array(array);
	ft_error();
}

void	ft_free_stack(t_node **stack, int size)
{
	t_node	*node;
	t_node	*temp;
	int		i;

	if (!stack || !*stack)
		return ;
	node = *stack;
	i = 0;
	while (i < size)
	{
		temp = node->next;
		free(node);
		node = temp;
		i++;
	}
	*stack = NULL;
}

void	ft_free_stack_and_str_err(t_node **stack, char *str)
{
	free(str);
	ft_free_stack(stack, stack_size(*stack));
	get_next_line(0, 0);
	ft_error();
}
