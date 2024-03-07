/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 20:01:55 by rapcampo          #+#    #+#             */
/*   Updated: 2024/03/07 20:52:57 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdbool.h>

static void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while (*a != cheapest_node->target_node
			&& *b != cheapest_node)
		rr(a, b, false);
	set_current_position(*a);
	set_current_position(*b);
}

static void	reverse_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while (*a != cheapest_node->target_node
			&& *b != cheapest_node)
		rr(a, b, false);
	set_current_position(*a);
	set_current_position(*b);
}

void	finish_rotation(t_stack **stack, t_stack *top_node, char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median)
				ra(stack, false);
			else
			 	rra(stack, false);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_median)
				rb(stack, false);
			else
			 	rrb(stack, false);
		}
	}
}

 static void	move_nodes(t_stack **a, t_stack **b)
{
	t_stack	*cheapest_node;

	cheapest_node = return_cheapest(*b);
	if (cheapest_node->above_median
			&& cheapest_node->target_node->above_median)
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_median)
			&& !(cheapest_node->target_node->above_median))
		reverse_rotate_both(a, b, cheapeast_node);
	finish_rotation(b, cheapest_node, 'b');
	finish_rotation(a, cheapest_node->target_node, 'a');
	pa(a, b, false);
}

void	push_swap(t_stack **a, t_stack **b)
{
	t_stack	*smallest;
	int		len_a;

	len_a = stack_len(*a);
	while (len_a-- > 3)
		pb(b, a, false);
	while (*b)
	{
		init_nodes(*a, *b);
		move_nodes(a, b);
	}
	set_current_position(*a);
	smallest = find_smallest(*a);
	if (smallest->above_median)
		while (*a != smallest)
			ra(a, false);
	else
	 	while(*a != smallest)
			rra(a, false);
}
