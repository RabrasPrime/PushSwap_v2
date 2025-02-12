/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opti.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjooris <tjooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:20:50 by tjooris           #+#    #+#             */
/*   Updated: 2025/02/12 15:23:35 by tjooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPTI_H
# define OPTI_H
# include "struct.h"

/*=-=-=-=-=-=-=-=-=-MOVEMENT OPTIMIZATION-=-=-=-=-=-=-=-=-=*/

void	moves_init(t_node **stack_a, int n);
void	do_moves(t_node **stack_a, t_node **stack_b, t_node **node);
void	find_best_push(t_node **stack_a, t_node **stack_b);
void	prepare_stack_a(t_node **stack_a, t_node **b);

#endif