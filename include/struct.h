/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjooris <tjooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:13:48 by tjooris           #+#    #+#             */
/*   Updated: 2025/02/12 15:55:02 by tjooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

/*=-=-=-=-=-=-=-=-=-STRUCTURES-=-=-=-=-=-=-=-=-=*/

typedef struct s_node
{
	int				nb;
	int				index;
	int				value;
	int				sa;
	int				sb;
	int				ra;
	int				rb;
	int				rra;
	int				rrb;
	int				move;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_seq
{
	int		curr_len;
	int		max_len;
	int		index;
	int		max_index;
	int		start;
}	t_seq;

typedef struct s_max
{
	int		nb;
	int		size;
}	t_max;

#endif