/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjooris <tjooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 03:41:05 by tjooris           #+#    #+#             */
/*   Updated: 2025/02/05 13:16:19 by tjooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "push_swap.h"

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
	*stack = NULL; // Sécurisation pour éviter d'accéder à une mémoire libérée
}

