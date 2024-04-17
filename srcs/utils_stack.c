/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 01:56:00 by rapcampo          #+#    #+#             */
/*   Updated: 2024/04/06 02:25:39 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_elem	*create_tab(int argc, char **argv, int boolean);
t_elem	get_min_stack(t_elem *stack);
t_elem	get_max_stack(t_elem *stack, int threshold);
t_elem	get_min_above_thresh(t_elem *stack, int threshold);
int		is_sorted(t_elem *stack);

t_elem	*create_tab(int argc, char **argv, int boolean)
{
	t_elem	*tab;

	auto int i = 0;
	tab = malloc(sizeof(t_elem) * (argc + 1));
	if (!tab)
		return (NULL);
	while (i < argc -1)
	{
		if (boolean == 1)
		{
			tab[i].num = ft_atoi(argv[i]);
			tab[i].filled = 1;
		}
		else
		{
			tab[i].num = 0;
			tab[i].filled = 0;
		}
		tab[i].index = i;
		i++;
	}
	tab[i].index = -1;
	return (tab);
}

t_elem	get_min_stack(t_elem *stack)
{
	auto int start = get_start_stack(stack);
	auto int end = get_end_stack(stack);
	auto int min = stack[start].index;
	while (start <= end)
	{
		if (stack[start].num < stack[min].num)
			min = stack[start].index;
		start++;
	}
	return (stack[min]);
}

t_elem	get_max_stack(t_elem *stack, int threshold)
{
	auto int start = get_start_stack(stack);
	auto int end = get_end_stack(stack);
	auto int max = -1;
	while (start <= end)
	{
		if (max == -1 || ((stack[start].num > stack[max].num
					|| stack[max].filled == -1) && (threshold == -1
					|| stack[start].num < threshold)))
			max = stack[start].index;
		start++;
	}
	return (stack[max]);
}

t_elem	get_min_above_thresh(t_elem *stack, int threshold)
{
	auto int start = get_start_stack(stack);
	auto int end = get_end_stack(stack);
	auto int min = -1;
	while (start <= end)
	{
		if (stack[start].num > threshold
			&& (min == -1 || stack[start].num < stack[min].num))
			min = stack[start].index;
		start++;
	}
	if (min == -1)
		return (get_min_stack(stack));
	return (stack[min]);
}

int	is_sorted(t_elem *stack)
{
	auto int i = 0;
	while (stack[i + 1].index != -1)
	{
		if (stack[i].num > stack[i + 1].num)
			return (-1);
		i++;
	}
	return (1);
}
