/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjooris <tjooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 13:46:09 by tjooris           #+#    #+#             */
/*   Updated: 2025/02/19 19:47:49 by tjooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	check_good_sort(t_node *stack_a, t_node *stack_b)
{
	t_node	*node;

	if (stack_b)
		return (0);
	node = stack_a;
	while (node->next->next != stack_a)
	{
		if (node->nb > node->next->nb)
			return (0);
		node = node->next;
	}
	if (node->nb > node->next->nb)
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	char	*str;
	char	**array;
	t_node	*stack_a;
	t_node	*stack_b;

	if (ac == 1)
		return (1);
	stack_a = NULL;
	array = NULL;
	array = args_handler(&ac, av);
	stack_a = stack_a_init(stack_a, array);
	ft_free_array(array);
	stack_b = NULL;
	str = "";
	while (str)
	{
		str = get_next_line(0, 1);
		do_moves_bonus(str, &stack_a, &stack_b);
		free(str);
	}
	if (check_good_sort(stack_a, stack_b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_free_stack(&stack_a, stack_size(stack_a));
}
