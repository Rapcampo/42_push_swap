/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operatios.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 20:40:34 by rapcampo          #+#    #+#             */
/*   Updated: 2024/04/06 21:03:03 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_stack(t_elem *stack_a, t_elem *stack_b, char *op);
void	shift_up(t_elem *stack, char *op);
void	shift_down(t_elem *stack, char *op);
void	ft_swap(t_elem *stack, char *op);
void	ft_double_shift(t_elem *stack_a, t_elem *stack_b, int down_up);

void	push_stack(t_elem *stack_a, t_elem *stack_b, char *op)
{
	auto int	first = 0;
	auto int	end = 0;
	while (stack_a[first].filled != 1)
		first++;
	while (stack_b[end].index != -1 && stack_b[end].filled != 1)
		end++;
	end--;
	stack_b[end].num = stack_a[first].num;
	stack_a[first].num = 0;
	stack_b[end].filled = 1;
	stack_a[first].filled = 0;
	ft_putstr_fd(op, 1);
}

void	shift_up(t_elem *stack, char *op)
{
	int	i;
	int	temp;
	int	temp2;

	auto int	start = 0;
	auto int	end = 0;
	while (stack[start].index != -1 && stack[start].filled != 1)
		start++;
	while (stack[end].index != -1)
		end++;
	end--;
	i = end;
	temp = stack[i].num;
	while (i > start)
	{
		temp2 = stack[i - 1].num;
		stack[i - 1].num = temp;
		temp = temp2;
		i--;
	}
	stack[end].num = temp;
	ft_putstr_fd(op, 1);
}

void	shift_down(t_elem *stack, char *op)
{
	int	i;
	int	temp;
	int	temp2;

	auto int	start = 0;
	auto int	end = 0;
	while (stack[start].index != -1 && stack[start].filled != 1)
		start++;
	while (stack[end].index != -1)
		end++;
	end--;
	i = start;
	temp = stack[i].num;
	while (i < end)
	{
		temp2 = stack[i + 1].num;
		stack[i + 1].num = temp;
		temp = temp2;
		i++;
	}
	stack[start].num = temp;
	ft_putstr_fd(op, 1);
}

void	ft_swap(t_elem *stack, char *op)
{
	auto int	start = get_start_stack(stack);
	stack[start].num ^= stack[start + 1].num;
	stack[start + 1].num ^= stack[start].num;
	stack[start].num ^= stack[start + 1].num;
	ft_putstr_fd(op, 1);
}

void	ft_double_shift(t_elem *stack_a, t_elem *stack_b, int down_up)
{
	if (down_up == 1)
	{
		shift_down(stack_a, "");
		shift_down(stack_b, "");
		ft_putstr_fd("rrr\n", 1);
	}
	else
	{
		shift_up(stack_a, "");
		shift_up(stack_b, "");
		ft_putstr_fd("rr\n", 1);
	}
}
