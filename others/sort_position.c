#include "../push_swap.h"

int	search_min(t_list **stack_a)
{
	t_list	*p;
	int		min;

	p = *stack_a;
	min = p->value;
	while (p->next != *stack_a)
	{
		p = p->next;
		if (p->value < min)
			min = p->value;
	}
	return (min);
}

int	search_p(t_list **stack_a)
{
	t_list	*p;
	int		max;
	int		i;

	p = *stack_a;
	max = search_min(&(*stack_a));
	i = 1;
	while (p->next != *stack_a)
	{
		if (p->value > max && p->pos == 0)
			max = p->value;
		i++;
		p = p->next;
	}
	if (p->value > max && p->pos == 0)
		max = p->value;
	p = p->next;
	return (max);
}

void	search_pos(t_list **stack_a, int col)
{
	t_list	*p;
	int		elem;

	p = *stack_a;
	elem = search_p(&(*stack_a));
	while (p->next != *stack_a)
	{
		if (p->value == elem)
			p->pos = col;
		p = p->next;
	}
	if (p->value == elem)
		p->pos = col;
	p = p->next;
}

void	make_sort_position(int argc, t_list **stack_a)
{
	int	col;

	col = argc - 1;
	while (col > 0)
	{
		search_pos(&(*stack_a), col);
		col--;
	}
}
