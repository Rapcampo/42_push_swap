/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 09:41:18 by rapcampo          #+#    #+#             */
/*   Updated: 2024/02/07 10:23:50 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "libft.h"
# include <limits.h>
# include <stdbool.h>

/*typedef enum operations
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR
}		t_operations;
*/
typedef struct s_stack
{
	int 			nbr;
	int 			index;
	int				push_cost;
	bool			above_median;
	bool			cheapest;
	struct s_stack	*target_node;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

// input handler

char	**ft_insplit(char *str, char separator);

// hadle errors

void	free_matrix(char **argv);
void	error_free(t_stack **a, char **argv, bool flag_argc_2);
void	free_stack(t_stack **stack);
int		error_repetition(t_stack *a, int nbr);
int		error_syntax(char *str_nbr);

// create stacks

void	init_stack(t_stack **a, char **argv, bool flag_argc_2);
void	init_nodes(t_stack *a, t_stack *b);
void	set_current_position(t_stack *stack);
void	set_price(t_stack *a, t_stack *b);
void	set_cheapest(t_stack *b);

// linked list ops

void	append_node(t_stack **stack, int nbr);
t_stack	*find_last_node(t_stack *head);
t_stack	*find_smallest(t_stack *stack);
t_stack	*return_cheapest(t_stack *stack);
bool	stack_sorted(t_stack *stack);
int		stack_len(t_stack *stack);
void	finish_rotation(t_stack	**s, t_stack *n, char c);


// sort algo

void	sort_three(t_stack **a);
void	push_swap(t_stack **a, t_stack **b);

// swap node ops

void	sa(t_stack **a, bool checker);
void	sb(t_stack **b, bool checker);
void	ss(t_stack **a, t_stack **b, bool checker);

// rotate node ops

void	ra(t_stack **a, bool checker);
void	rb(t_stack **b, bool checker);
void	rr(t_stack **a, t_stack **b, bool checker);

// reverse rotate ops

void	rra(t_stack **a, bool checker);
void	rrb(t_stack **b, bool checker);
void	rrr(t_stack **a, t_stack **b, bool checker);

// push ops

void	pa(t_stack **a, t_stack **b, bool checker);
void	pb(t_stack **b, t_stack **a, bool checker);

# endif
