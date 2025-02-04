/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjooris <tjooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 03:41:05 by tjooris           #+#    #+#             */
/*   Updated: 2025/02/04 03:41:06 by tjooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "push_swap.h"

void	ft_free_stack(t_node **stack, int size)
{
	t_node	*node;
	int		i;

	i = 0;
	node = *stack;
	while (i < size - 1)
	{
		node = node->next;
		free(node->prev);
		i++;
	}
	free(node);
}
