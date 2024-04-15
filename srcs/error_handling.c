/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 00:40:22 by rapcampo          #+#    #+#             */
/*   Updated: 2024/04/06 01:06:46 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

int		is_args_number(int argc, char **argv);
int		is_duplicate(int argc, char **argv);
int		ft_handle_errors(int argc, char **argv);
long	ft_atol(char *nptr);

long	ft_atol(char *nptr)
{
	auto long nbr = 0;
	auto int	i = 0;
	auto int	neg = 1;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			neg = -1;
		i++;
	}
	while (nptr[i])
	{
		if (nptr[i] >= '0' && nptr[i] <= '9')
			nbr = (nbr * 10) + (nptr[i] - 48);
		else
			return (2147483650);
		i++;
	}
	return (nbr * neg);
}

int	is_args_number(int argc, char **argv)
{
	int	j;

	auto int	i = 0;
	while (i < argc - 1)
	{
		j = 0;
		if (!(argv[i][0] == '+' || argv[i][0] == '-' 
					|| (argv[i][0] >= '0' && argv[i][0] <= '9')))
			return (-1);
		while (argv[i][j])
		{
			if ((argv[i][j] == '+' || argv[i][j] == '-') 
					&& (ft_isdigit(argv[i][j + 1] == 0) || !argv[i][j + 1]))
				return (-1);
			if (ft_isdigit(argv[i][j] == 0 && (argv[i][j])))
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int	is_duplicate(int argc, char **argv)
{
	int	j;

	if (argc == 2)
	{
		if (ft_atol(argv[0]) > INT_MAX || ft_atol(argv[0]) < INT_MIN)
			return (-1);
	}
	auto int	i = -1;
	while (++i < argc - 1)
	{
		j = i + 1;
		if (ft_atol(argv[i]) > INT_MAX || ft_atol(argv[i]) < INT_MIN)
			return (-1);
		while (j < argc - 1)
		{
			if (ft_atol(argv[i]) == ft_atol(argv[j]))
				return (-1);
			j++;
		}
	}
	return (0);
}

int	ft_handle_errors(int argc, char **argv)
{
	if (argc == 1)
		return (0);
	if (is_args_number(argc, argv) == -1)
	{
		ft_putstr_fd("Error\n", 2);
		return (-1);
	}
	if (is_duplicate(argc, argv) == -1)
	{
		ft_putstr_fd("Error\n", 2);
		return (-1);
	}

		return (1);
}
