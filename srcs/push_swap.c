/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 23:28:04 by rapcampo          #+#    #+#             */
/*   Updated: 2024/04/17 17:35:16 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			choose_resolve(t_elem *stack_a, t_elem *stack_b, int argc);
static void		ft_free(t_elem *stack_a, t_elem *stack_b,
					char **split_list, int tofree);

void	choose_resolve(t_elem *stack_a, t_elem *stack_b, int argc)
{
	if (argc == 3)
	{
		if (is_sorted(stack_a) == -1)
			ft_swap(stack_a, "sa\n");
	}
	else if (argc == 4)
		tiny_sort(stack_a);
	else
		resolve_stack(stack_a, stack_b, argc);
}

static void	ft_free(t_elem *stack_a, t_elem *stack_b,
	char **split_list, int tofree)
{
	auto int i = 0;
	if (tofree)
	{
		while (split_list[i])
		{
			free(split_list[i]);
			i++;
		}
		free(split_list[i]);
		free(split_list);
	}
	if (stack_a)
		free(stack_a);
	if (stack_b)
		free(stack_b);
}

int	main(int argc, char **argv)
{
	int			error;
	t_elem		*stack_a;
	t_elem		*stack_b;
	char		**split_list;

	auto int tofree = 0;
	argv++;
	split_list = argv;
	error = ft_handle_errors(argc, split_list);
	if (error == -1 || error == 0)
	{
		ft_free(NULL, NULL, split_list, tofree);
		return (0);
	}
	stack_a = create_tab(argc, split_list, 1);
	stack_b = create_tab(argc, split_list, 0);
	if (is_sorted(stack_a) == -1)
		choose_resolve(stack_a, stack_b, argc);
	ft_free(stack_a, stack_b, split_list, tofree);
	return (0);
}
