/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorythm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 13:17:42 by rapcampo          #+#    #+#             */
/*   Updated: 2024/04/06 17:06:12 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		r_top(t_elem *stack_a, int index, char *r, char *rr);
void	resolve_coherences(t_elem *stack_a, t_elem *stack_b, int index);
void	resolve_num(t_elem *stack_a, t_elem *stack_b, int index, int stack_size);
int		get_median(t_elem *stack);
void	resolve_stack(t_elem *stack_a, t_elem *stack_b, int stack_size);

int	r_top(t_elem *stack_a, int index, char *r, char *rr)
{
	int	op;

	auto int	nb_op = get_op_for_topplace(stack_a, index, 1);
	auto int	sign = nb_op;
	if (nb_op < 0)
		nb_op = -nb_op;
	op = nb_op;
	if (nb_op)
	{
		while (nb_op > 0)
		{
			if (sign > 0)
				shift_up(stack_a, r);
			else
				shift_down(stack_a, rr);
			nb_op--;
		}
	}
	if (sign > 0)
		sign = 1;
	else
		sign = -1;
	return (sign * op);
}

void	resolve_coherences(t_elem *stack_a, t_elem *stack_b, int index)
{
	auto int	dist = get_coherences(stack_a, stack_b, index);
	if (dist > 0)
	{
		while (dist > 0)
		{
			ft_double_shift(stack_a, stack_b, 0);
			dist--;
		}
	}
	else if (dist < 0)
	{
		dist = -dist;
		while (dist > 0)
		{
			ft_double_shift(stack_a, stack_b, 1);
			dist--;
		}
	}
}

void	resolve_num(t_elem *stack_a, t_elem *stack_b, int index, int stack_size)
{
	auto int	start = get_start_stack(stack_a);
	auto int	same = get_coherences(stack_a, stack_b, index);
	resolve_coherences(stack_a, stack_b, index);
	if (same)
		index -= same;
	if (index >= stack_size - 2)
		index = start + (index - (stack_size -1));
	else if (index < start)
		index = get_end_stack(stack_a) + index;
	index -= r_top(stack_a, index, "rb\n", "rrb\n");
	if (index >= stack_size - 2)
		index = start + (index - (stack_size - 1));
	if (get_min_stack(stack_b).num > stack_a[index].num || get_max_stack(stack_b, -1).num < stack_a[index].num)
		r_top(stack_b, get_min_stack(stack_b).index, "ra\n", "rra\n");
	else
		r_top(stack_b, get_min_above_thresh(stack_b, stack_a[index].num).index, "ra\n", "rra\n");
	push_stack(stack_a, stack_b, "pa\n");
}

int	get_median(t_elem *stack)
{
	auto int	start = get_start_stack(stack);
	auto int	end = get_end_stack(stack);
	while (start <= end)
	{
		if (is_median(stack, stack[start].num))
			return (stack[start].num);
		start++;
	}
	return (-1);
}

void	resolve_stack(t_elem *stack_a, t_elem *stack_b, int stack_size)
{
	auto int	index = get_start_stack(stack_a);
	auto int	median = get_median(stack_a);
	while (index < stack_size - 4)
	{
		push_stack(stack_a, stack_b, "pb\n");
		if (stack_b[get_start_stack(stack_b)].num > median && get_end_stack(stack_a) - get_start_stack(stack_a) + 1 > 3)
			shift_up(stack_b, "rb\n");
		index++;
	}
	tiny_sort(stack_a);
	index = get_start_stack(stack_b);
	while (index < get_end_stack(stack_b))
	{
		resolve_num(stack_b, stack_a, get_best_op_index(stack_b, stack_a, stack_size), stack_size);
		index++;
	}
	r_top(stack_a, get_min_above_thresh(stack_a, stack_b[index].num).index, "ra\n", "rra\n");
	push_stack(stack_b, stack_a, "pa\n");
	r_top(stack_a, get_min_stack(stack_a).index, "ra\n", "rra\n");
}
