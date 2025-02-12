/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjooris <tjooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 11:37:50 by tjooris           #+#    #+#             */
/*   Updated: 2025/02/12 16:01:31 by tjooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"
#include "libft.h"
#include "stack.h"

static void	test_one_arg(char *str, char **array)
{
	int	i;

	if ((str[0] == '-' && str[1] == '\0') || (str[0] == '+' && str[1] == '\0'))
	{
		ft_free_array(array);
		ft_error();
	}
	if (!(str[0] == '-' || str[0] == '+' || (str[0] >= 48 && str[0] <= 57)))
	{
		ft_free_array(array);
		ft_error();
	}
	i = 0;
	while (str[++i])
	{
		if (!(str[i] >= 48 && str[i] <= 57))
		{
			ft_free_array(array);
			ft_error();
		}
	}
	ft_atoi(str);
	ft_free_array(array);
	exit(0);
}

char	**handle_single_argument(char *arg)
{
	char	**array;

	array = ft_split(arg, ' ');
	if (!array || !array[0])
	{
		if (!array)
			ft_error();
		else
			ft_free_array_error(array);
	}
	if (!array[1])
		test_one_arg(array[0], array);
	return (array);
}

char	**handle_multiple_arguments(int ac, char **av)
{
	char	**array;
	int		i;

	array = malloc(sizeof(char *) * ac);
	if (!array)
		return (NULL);
	i = 0;
	while (++i < ac)
	{
		array[i - 1] = ft_strdup(av[i]);
		if (!array[i - 1])
		{
			ft_free_array(array);
			ft_error();
		}
	}
	array[i - 1] = NULL;
	return (array);
}

char	**args_handler(int *ac, char **av)
{
	char	**array;

	if (*ac < 2)
		exit(1);
	else if (*ac == 2)
		array = handle_single_argument(av[1]);
	else
		array = handle_multiple_arguments(*ac, av);
	*ac = ft_array_size(array);
	return (array);
}
