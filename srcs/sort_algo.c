#include "../includes/push_swap.h"

void		transfer_cheap(t_list **a, t_list **b, int size_a, int size_b);
void		sort_three(t_list **list, char type);
static void	calculate_cost(t_list *a, t_list *b, int size_a, int size_b);
static void	transfer(t_list **a, t_list **b, t_list *cheapest);
static int	transfer_formula(t_list *list);

void	sort_three(t_list **list, char type)
{
	if (!(*list))
		return ;
	if (type == 'a' && (*list)->r_v)
}
