/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 01:37:01 by rapcampo          #+#    #+#             */
/*   Updated: 2024/04/17 17:42:24 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_min(int a, int b);
int	ft_max(int a, int b);
int	get_start_stack(t_elem *stack);
int	get_end_stack(t_elem *stack);
int	is_median(t_elem *stack, int num);

int	ft_min(int a, int b)
{
	if (a <= b)
		return (a);
	return (b);
}

int	ft_max(int a, int b)
{
	if (a >= b)
		return (a);
	return (b);
}

int	get_start_stack(t_elem *stack)
{
	auto int first = 0;
	while (stack[first].filled != 1)
		first++;
	if (stack[first].index == -1)
		first--;
	return (first);
}

int	get_end_stack(t_elem *stack)
{
	auto int end = 0;
	while (stack[end].index != -1)
		end++;
	end--;
	return (end);
}

int	is_median(t_elem *stack, int num)
{
	auto int start = get_start_stack(stack);
	auto int end = get_end_stack(stack);
	auto int higher = 0;
	auto int lower = 0;
	while (start <= end)
	{
		if (stack[start].num > num)
			higher++;
		else if (stack[start].num < num)
			lower++;
		start++;
	}
	if ((higher - lower) >= -1 && (higher - lower) <= 1)
		return (1);
	return (0);
}
