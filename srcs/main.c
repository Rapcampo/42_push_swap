/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:48:40 by rapcampo          #+#    #+#             */
/*   Updated: 2024/02/21 17:49:54 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

int main (int argc, char **argv)
{
	t_stack	*sa;
	t_stack	*sb;
	int		*n_array;
	int		size;

	sa = NULL;
	sb = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	init_stack_a(&sa, argv + 1);
	if (!stack_sorted(sa))
	{
		if (stack_len(sa) == 2)
			sa(&a, false);
		else if (stack_len(sa) == 3)
			sort_three(&sa);
		else
		 	sort_stacks(&sa, &sb);
	}
	free_stack(&sa);
	return (0);

}
