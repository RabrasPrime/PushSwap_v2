/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjooris <tjooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:19:51 by tjooris           #+#    #+#             */
/*   Updated: 2025/02/04 17:53:09 by tjooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <limits.h>

void	error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

#include <limits.h>

int	ft_atoi(const char *nptr)
{
	int			i;
	int			sign;
	long		result;

	i = 0;
	sign = 1;
	result = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	if (!nptr[i])
		ft_error();
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		if ((result > (LONG_MAX / 10)) || (result == (LONG_MAX / 10) && (nptr[i] - '0') > (LONG_MAX % 10)))
			return (sign == 1 ? INT_MAX : INT_MIN);
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	if (nptr[i] != '\0')
		ft_error();
	return ((int)(sign * result));
}

