#include "push_swap.h"

static t_stack	*get_next_min(t_stack **stack)
{
	t_stack	*min;
	t_stack	*current;
	
	min = NULL;
	current = *stack;
	while (current)
	{
		if (current->index == -1 && (min == NULL || current->value < min->value))
			min = current;
		current = current->next;
	}
    return (min);
}

void ft_index(t_stack **stack)
{
	t_stack	*current;
	int	index;

	current = get_next_min(stack);
	index = 0;
	while (current)
	{
		current->index = index++;
		current = get_next_min(stack);
	}
}
