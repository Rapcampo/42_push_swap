/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 22:06:15 by jduraes-          #+#    #+#             */
/*   Updated: 2024/01/08 22:06:58 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	checkrepeat(char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
		{
			if (ft_atol(argv[i]) == ft_atol(argv[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	wrongargs(char **argv)
{
	int		i;
	int		j;
	long	nr;

	i = 0;
	j = 0;
	nr = 0;
	while (argv[i])
	{
		j = 0;
		nr = ft_atol(argv[i]);
		if (nr < INT_MIN || nr > INT_MAX || argv[i][j] == '\0')
			return (1);
		if (argv[i][j] == '-' && ft_isdigit(argv[i][j + 1]))
			j++;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j++]))
				return (1);
		}
		i++;
	}
	if (checkrepeat(argv))
		return (1);
	return (0);
}
