#include "../includes/push_swap.h"

static long	ft_atol(const char *str)
{
	long	result;
	int		sign;
	int		i;
	
	i = 0;
	result = 0;
	sign = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n' || 
			*str == '\r' || *str == '\f' || *str == '\v')
		i++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= 0 && str[i] <= 9)
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

void	init_stack(t_stack **a, char **argv, bool flag_argc_2)
{
	long	n;
	int		i;

	i = 0;
	while (argv[1])
	{
		if (error_syntax(argv[1]))
			error_free(a, argv, flag_argc_2);
		n = ft_atol(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
			error_free(a, argv, flag_argc_2);
		if (error_repetition(*a, (int)n))
			error_free(a, argv, flag_argc_2);
		append_node(a, (int)n);
		i++;
	}
	if (flag_argc_2)
		free_matrix(argv);
}
