#include "../../push_swap.h"

void	push_in_b(t_next *next, t_list **stack_a, t_list **stack_b)
{
	t_list	*p;

	p = *stack_a;
	if (p->pos > next->push_more && p->pos <= next->push_less)
	{
		if (p->pos > next->max_b)
			next->max_b = p->pos;
		ft_pb(&(*next), &(*stack_a), &(*stack_b));
	}
	else
		ft_ra(&(*next), &(*stack_a));
}

void	fill_flags(t_next *next, t_list **stack_b)
{
	t_list	*p;

	p = *stack_b;
	while (p->next != *stack_b)
	{
		p->flag = next->flag + 1;
		p = p->next;
		if (p->next == *stack_b)
		{
			p->flag = next->flag + 1;
			break ;
		}
	}
	*stack_b = p->next;
}

int	search_min_for_mid(int min, t_list **p)
{
	if ((*p)->pos < min)
		min = (*p)->pos;
	return (min);
}

int	search_mid_a(t_next *next, t_list **stack_a)
{
	t_list	*p;
	int		max;
	int		min;
	int		save_fl;

	p = *stack_a;
	min = p->pos;
	max = p->pos;
	save_fl = p->flag;
	while (p->flag == save_fl && p->next != *stack_a)
	{
		min = search_min_for_mid(min, &p);
		if (p->pos > max)
			max = p->pos;
		p = p->next;
		if (p->next == *stack_a && p->flag == save_fl)
		{
			min = search_min_for_mid(min, &p);
			if (p->pos > max)
				max = p->pos;
		}
	}
	if (min == 1)
		min = 0;
	return ((max - min) / 2 + next->next_el);
}
