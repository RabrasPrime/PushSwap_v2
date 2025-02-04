/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjooris <tjooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 03:41:09 by tjooris           #+#    #+#             */
/*   Updated: 2025/02/04 03:41:09 by tjooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "push_swap.h"

void	sa(t_node **stack, int a)
{
	t_node	*node;
	int		tmp;

	node = *stack;
	tmp = node->nb;
	node->nb = node->next->nb;
	node->next->nb = tmp;
	tmp = node->index;
	node->index = node->next->index;
	node->next->index = tmp;
	if (a)
		write(1, "sa\n", 3);
}

void	sb(t_node **stack, int a)
{
	t_node	*node;
	int		tmp;

	node = *stack;
	tmp = node->nb;
	node->nb = node->next->nb;
	node->next->nb = tmp;
	tmp = node->index;
	node->index = node->next->index;
	node->next->index = tmp;
	if (a)
		write(1, "sb\n", 3);
}
