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


// rotate stack operations

void	ra(t_stack **a, bool checker);
void	rb(t_stack **b, bool checker);
void	rr(t_stack **a, t_stack **b, bool checker);

# endif
