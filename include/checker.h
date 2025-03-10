/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjooris <tjooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 09:18:10 by tjooris           #+#    #+#             */
/*   Updated: 2025/02/19 19:39:33 by tjooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "struct.h"
# include "stack.h"
# include "arg.h"
# include "get_next_line.h"
# include "libft.h"
# include "push.h"

/*=-=-=-=-=-=-=-=-=-STACK FUNCTIONS-=-=-=-=-=-=-=-=-=*/

void	pile_down(t_node **stack, t_node *node);

/*=-=-=-=-=-=-=-=-=-BONUS FUNCTIONS-=-=-=-=-=-=-=-=-=*/

void	do_moves_bonus(char *str, t_node **stack_a, t_node **stack_b);

#endif
