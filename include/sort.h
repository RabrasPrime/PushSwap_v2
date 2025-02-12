/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjooris <tjooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:17:20 by tjooris           #+#    #+#             */
/*   Updated: 2025/02/12 15:23:08 by tjooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H

# include "struct.h"

/*=-=-=-=-=-=-=-=-=-SORTING FUNCTIONS-=-=-=-=-=-=-=-=-=*/

void	quicksort(t_node *stack, int *array, int start, int end);
void	sort_three_numbers(t_node **stack);
void	sort_five_numbers(t_node **stack_a, t_node **stack_b);
void	big_sort(t_node **stack_a, t_node **stack_b);

#endif