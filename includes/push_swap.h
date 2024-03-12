#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <cstddef>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_list
{
	int				value;
	size_t			r_v;
	int				transfer_cost_a;
	int				transfer_cost_b;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

t_list	*init_stack(long *numbers);
void	sort_three(t_list **list, char type);
void	transfer_cheap(t_list **a, t_list **b, int size_a, int size_b);
void	op_list(t_list **a, t_list **b, char *op);
char	**ft_split(char const *s, char c);
size_t	count_list(t_list *list);
int		check_duplicate(long n, long *numbers);
void	free_list(t_list *list);
int		check_sort(t_list *list, char order);
int		find_next(t_list *list, int size, int min, int max);
void	*ft_calloc(size_t nmemb, size_t size);
size_t	array_len(char **array);
size_t	str_len(char *str);
long	ft_atol(char *nptr);
int		ft_strcmp(const char *str1, const char *str2);

#endif
