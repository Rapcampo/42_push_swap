#include "../includes/push_swap.h"

static long	ft_atol(const char *str)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n' || 
			*str == '\r' || *str == '\f' || *str == '\v')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (ft_isdigit(*str))
		result = result * 10 + (*str++ - '0');
	return (result * sign);
}

static void	append_node(t_stack **stack, int n)
{
	t_stack	*node;
	t_stack *last_node;

	if (!stack)
		return ;
	node = malloc(sizeof(t_stack));
	if (!node)
		return ;
	node->next = NULL;
	node->nbr = n;
	if (!(*stack))
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

void	init_stack(t_stack **a, char **argv, bool flag_argc_2)
{
	long	n;
	int		i;

	i = 0;
	while (argv[1])
	{
		if (error_syntax(argv[1]))
			free_error(a, argv, flag_argc_2);
		n = ft_atol(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
			free_error(a, argv, flag_argc_2);
		if (error_repetition(*a, (int)n))
			free_error(a, argv, flag_argc_2);
		append_node(a, (int)n);
		i++;
	}
	if (flag_argc_2)
		free_matrix(argv);
}
