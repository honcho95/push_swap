#include "push_swap.h"

static void	init(t_stack **stack, int ac, char **av)
{
	t_stack	*new;
	char	**at;
	int		i;

	i = 0;
	
	i = 0;
	if (ac ==2)
		at = ft_split(av[1], ' ');
	else
	{
		i = 1;
		at = av;
	}
	while (at[i])
	{
		new = ft_lstnew(ft_atoi(at[i]));
		ft_lstadd_back(stack, new);
		i++;
	}
	ft_index(stack);
	if (ac == 2)
		ft_free(at);
}

static void	sort(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_lstsize(*stack_a) <= 5)
		small_sort(stack_a, stack_b);
	else
		big_sort(stack_a, stack_b);
}

int	main(int ac, char **av)
{
	t_stack	**stack_a;
	t_stack	**stack_b;

	if (ac < 2)
		return (-1);
	is_valid(ac, av);
	stack_a = (t_stack **)malloc(sizeof(t_stack));
	stack_b = (t_stack **)malloc(sizeof(t_stack));
	*stack_a = NULL;
	*stack_b = NULL;
	init(stack_a, ac, av);
	if (is_sorted(stack_a))
	{
		free_stack(stack_a);
		free_stack(stack_b);
		return (0);
	}
	sort(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
