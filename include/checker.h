/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjooris <tjooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 09:18:10 by tjooris           #+#    #+#             */
/*   Updated: 2025/02/12 11:56:32 by tjooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "push_swap.h"
# include "get_next_line.h"
# include "libft.h"

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

/*=-=-=-=-=-=-=-=-=-STACK FUNCTIONS-=-=-=-=-=-=-=-=-=*/

void	pile_down(t_node **stack, t_node *node);

/*=-=-=-=-=-=-=-=-=-BONUS FUNCTIONS-=-=-=-=-=-=-=-=-=*/

void	do_moves_bonus(char *str, t_node **stack_a, t_node **stack_b);

#endif
