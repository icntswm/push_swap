#include "../../push_swap.h"

int	check_posit_a(int mid, t_list **stack)
{
	t_list	*p;
	int		i;

	i = 0;
	p = *stack;
	while (p->next != *stack)
	{
		if (p->pos <= mid)
			i++;
		p = p->next;
		if (p->pos <= mid)
			i++;
	}
	return (i);
}

int	check_posit_b(int mid, t_list **stack)
{
	t_list	*p;
	int		i;

	i = 0;
	p = *stack;
	while (p->next != *stack)
	{
		if (p->pos >= mid || p->next->pos >= mid)
			i++;
		p = p->next;
		if (p->pos >= mid || p->next->pos >= mid)
			i++;
	}
	return (i);
}

int	search_pos_next_in_b(t_next *next, t_list **stack_b)
{
	t_list	*p;
	int		pos;
	int		i;

	i = 1;
	p = *stack_b;
	pos = p->pos;
	while (p->next != *stack_b)
	{
		if (p->pos == next->next_el)
			pos = i;
		i++;
		p = p->next;
	}
	return (pos);
}

int	check_last_flag_in_a(t_list **stack_a)
{
	t_list	*p;
	int		j;

	p = *stack_a;
	j = 0;
	while (p->next != *stack_a)
	{
		j++;
		p = p->next;
	}
	return (p->pos);
}

int	search_max_a(t_list **stack_a)
{
	t_list	*p;
	int		max;

	p = *stack_a;
	max = p->value;
	while (p->next != *stack_a)
	{
		if (p->value > max)
			max = p->value;
		p = p->next;
		if (p->value > max)
			max = p->value;
	}
	return (max);
}
