/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjooris <tjooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:15:23 by tjooris           #+#    #+#             */
/*   Updated: 2025/02/12 15:22:56 by tjooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H
# include "struct.h"

/*=-=-=-=-=-=-=-=-=-STACK FUNCTIONS-=-=-=-=-=-=-=-=-=*/

t_node	*stack_a_init(t_node *stack, char **array);
t_node	*create_node(int value);
void	pile_down(t_node **stack, t_node *node);
int		stack_size(t_node *stack);
int		*stack_dup(int *array, t_node *stack);
void	index_init(t_node *stack);
void	ft_free_stack(t_node **stack, int size);
void	ft_free_stack_and_array_error(t_node **stack, char **array);
void	ft_free_array_error(char **array);

#endif