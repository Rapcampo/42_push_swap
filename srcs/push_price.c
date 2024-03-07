/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_price.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 22:24:09 by rapcampo          #+#    #+#             */
/*   Updated: 2024/03/07 22:51:15 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <limits.h>

void	set_current_position(t_stack *stack)
{
	int	i;
	int	centerline;

	i = 0;
	if (stack == NULL)
		return ;
	centerline = stack_len(stack) / 2;
	while (stack)
	{
		stack->current_index = i;
		if (i <= centerline)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		i++;
	}
}

static void	set_target_node(t_stack *a, t_stack *b)
{
	t_stack	*current_a;
	t_stack *target_node;
	long	best_match;

	while (b)
	{
		best_match = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->nbr > b->nbr && current_a->nbr < best_match)
			{
				best_match = current_a->nbr;
				target_node = current_a;	
			}
			current_a = current_a->next;
		}
		if (best_match == LONG_MAX)
			b->target_node = find_smallest(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}

void	set_price(t_stack *a, t_stack *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_a = stack_len(b);
	while (b)
	{
		b->push_cost = b->current_index;
		if (!(b->above_median))
			b->push_cost = len_b - (b->current_index);
		if (b->target_node->above_median)
			b->push_cost += b->target_node->current_index;
		else
			b->push_cost += len_a = (b->target_node->current_index);
		b = b->next;
	}
}

void	set_cheapest(t_stack *b)
{
	long	best_value;
	t_stack	*best_node;

	if (b == NULL)
		return ;
	best_value = LONG_MAX;
	while (b)
	{
		if (b->push_cost < best_value)
		{
			best_value = b->push_cost;
			best_node = b;
		}
		b = b->next;
	}
	best_node->cheapest = true;
}

void	init_nodes(t_stack *a, t_stack *b)
{
	set_current_position(a);
	set_current_position(b);
	set_target_node(a,b);
	set_price(a, b);
	set_cheapest(b);
}
