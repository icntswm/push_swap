#include "../../push_swap.h"

int	stack_counter(t_list **stack)
{
	t_list	*p;
	int		i;

	i = 1;
	p = *stack;
	while (p->next != *stack)
	{
		p = p->next;
		i++;
	}
	return (i);
}
