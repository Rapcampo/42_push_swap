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
	if (type == 'a' && (*list)->r_v > ((*list)->next)->r_v
			&& (*list)->r_v > ((*list)->prev)->r_v)
		op_list(list, NULL, "rra");
	if (type == 'a' && (*list)->r_v < ((*list)->next)->r_v
			&& ((*list)->next)->r_v > ((*list)->prev)->r_v)
		op_list(list, NULL, "rra");
	if (type == 'a' && (*list)->r_v > ((*list)->next)->r_v)
		op_list(list, NULL, "sa");
	if (type == 'a' && (*list)->r_v > ((*list)->prev)->r_v)
		op_list(list, NULL, "ra");
	if (type == 'b' && (*list)->r_v < ((*list)->next)->r_v
			&& (*list)->r_v < ((*list)->prev)->r_v)
		op_list(NULL, list, "rrb");
	if (type == 'b' && (*list)->r_v > ((*list)->next)->r_v
			&& ((*list)->next)->r_v < ((*list)->prev)->r_v)
		op_list(NULL, list, "rrb");
	if (type == 'b' && (*list)->r_v < ((*list)->next)->r_v)
		op_list(NULL, list, "sb");
	if (type == 'b' && (*list)->r_v < ((*list)->prev)->r_v)
		op_list(NULL, list, "rb");
}

void	transfer_cheap(t_list **a, t_list **b, int size_a, int size_b)
{
	t_list *cheapest;
	int		i;

	cheapest = (*b);
	calculate_cost(*a, *b, size_a, size_b);
	i = 0;
	while (i++ < size_b)
	{
		if (transfer_formula(*b) < transfer_formula(cheapest))
			cheapest = (*b);
		(*b) = (*b)->next;
	}
	transfer(a, b, cheapest);
}

static void	calculate_cost(t_list *a, t_list *b, int size_a, int size_b)
{
	int	min;
	int	max;
	int	i;
	int	j;

	j = -1;
	while (++j < size_b)
	{
		min = -1;
		max = size_a + size_b;
		i = -1;
		while (++i < size_b)
		{
			if ((int)a->r_v > min && a->r_v < b->r_v)
				min = a->r_v;
			if ((int)a->r_v < max && a->r_v > b->r_v)
				max = a->r_v;
			a = a->next;
		}
		b->transfer_cost_b = j;
		if (j > (size_b / 2))
			b->transfer_cost_b = j - size_b;
		b->transfer_cost_a = find_next(a, size_a + size_b, min, max);
		b = b->next;
	}
}

static void	transfer(t_list **a, t_list **b, t_list *cheapest)
{
	while ((*b) != cheapest)
	{
		if (cheapest->transfer_cost_a < 0 && cheapest->transfer_cost_b < 0)
		{
			op_list(a, b, "rrr");
			cheapest->transfer_cost_a++;
		}
		else if (cheapest->transfer_cost_a > 0 && cheapest->transfer_cost_b > 0)
		{
			op_list(a, b, "rr");
			cheapest->transfer_cost_a--;
		}
		else if (cheapest->transfer_cost_b < 0)
			op_list(a, b, "rrb");
		else
		 op_list(a, b, "rb");
	}
	if ((*b)->transfer_cost_a > 0)
		while ((*b)->transfer_cost_a--)
			op_list(a, b, "ra");
	else if ((*b)->transfer_cost_a < 0)
		while ((*b)->transfer_cost_a++)
			op_list(a, b, "rra");
	op_list(a, b, "pa");
}

static int	transfer_formula(t_list *list)
{
	if (list->transfer_cost_a >= 0 && list->transfer_cost_b >= 0)
	{
		if (list->transfer_cost_a > list->transfer_cost_b)
			return (list->transfer_cost_a);
		else
			return (list->transfer_cost_b);
	}
	if (list->transfer_cost_a < 0 && list->transfer_cost_b < 0)
	{
		if (list->transfer_cost_a < list->transfer_cost_b)
			return (list->transfer_cost_a * -1);
		else
			return (list->transfer_cost_b * -1);
	}
	if (list->transfer_cost_b < 0)
		return ((list->transfer_cost_b * -1) + list->transfer_cost_a);
	else
		return (list->transfer_cost_b + (list->transfer_cost_a * -1));
}
