#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
//# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_elem
{
	int	num;
	int	filled;
	int	index;
}	t_elem;

int		ft_handle_errors(int argc, char **argv);
void	push_stack(t_elem *stack_a, t_elem *stack_b, char *op);
void	shift_up(t_elem *stack, char *op);
void	shift_down(t_elem *stack, char *op);
t_elem	*create_tab(int argc, char **argv, int boolean);
void	resolve_stack(t_elem *stack_a, t_elem *stack_b, int stack_size);
void	show_stack(t_elem *stack_a, t_elem *stack_b, int stack_size);
int		get_start_stack(t_elem *stack);
int		get_end_stack(t_elem *stack);
t_elem	get_max_stack(t_elem *stack, int threshold);
t_elem	get_min_stack(t_elem *stack);
int		get_op_for_topplace(t_elem *stack_a, int index, int reel);
int		get_op_for_gplace(t_elem *stack_a, t_elem *stack_b, int index);
void	tiny_sort(t_elem *stack);
void	ft_swap(t_elem *stack, char *op);
t_elem	get_min_above_thresh(t_elem *stack, int threshold);
void	ft_double_shift(t_elem *stack_a, t_elem *stack_b, int down_up);
int		get_coherences(t_elem *stack_a, t_elem *stack_b, int index);
int		ft_max(int a, int b);
int		ft_min(int a, int b);
int		get_best_op_index(t_elem *stack_a, t_elem *stack_b, int stack_size);
int		is_sorted(t_elem *stack);
int		is_median(t_elem *stack, int num);
long	ft_atol(char *nptr);

# endif
