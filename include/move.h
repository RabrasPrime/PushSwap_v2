/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjooris <tjooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:18:12 by tjooris           #+#    #+#             */
/*   Updated: 2025/02/12 15:31:16 by tjooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVE_H
# define MOVE_H
# include "struct.h"

/*=-=-=-=-=-=-=-=-=-MOVES-=-=-=-=-=-=-=-=-=*/

void	sa(t_node **stack, int a);
void	sb(t_node **stack, int a);
void	ra(t_node **stack, int a);
void	rb(t_node **stack, int a);
void	rr(t_node **stack_a, t_node **stack_b);
void	rra(t_node **stack, int a);
void	rrb(t_node **stack, int a);
void	rrr(t_node **stack_a, t_node **stack_b);
void	pb(t_node **stack_a, t_node **stack_b);
void	pa(t_node **stack_a, t_node **stack_b);

#endif