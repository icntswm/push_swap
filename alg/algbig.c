#include "../push_swap.h"

void	initialization(t_next *next, t_list **stack_a)
{
	next->next_el = 1;
	next->flag = -1;
	next->save_flag_in_a = (*stack_a)->flag;
	next->save_flag_in_b = 0;
	next->pos_nextel_b = 0;
	next->size_stack_b = 0;
	next->max_a = search_max_a(&(*stack_a));
	next->max_b = 0;
	next->mid_a = search_mid_a(&(*next), &(*stack_a));
	next->mid_b = 0;
	next->push_more = 0;
	next->push_less = next->mid_a;
}

void	algbig(t_next *next, t_list **stack_a, t_list **stack_b)
{
	initialization(&(*next), &(*stack_a));
	while ((*stack_a)->flag == next->save_flag_in_a)
	{
		push_in_b(&(*next), &(*stack_a), &(*stack_b));
		if (check_posit_a(next->mid_a, &(*stack_a)) == 0)
			break ;
	}
	next->mid_b = (next->max_b - next->next_el) / 2 + next->next_el;
	next->flag = next->flag + 2;
	next->save_flag_in_b = (*stack_b)->flag;
	push_a_frst_alg(&(*next), &(*stack_a), &(*stack_b));
	if (check_posit_a(next->mid_b, &(*stack_b)) == 0
		&& (*stack_b)->pos <= next->mid_b)
	{
		ft_pa(&(*next), &(*stack_b), &(*stack_a));
		(*stack_a)->flag = next->flag;
	}
	else if (check_posit_a(next->mid_b, &(*stack_b)) == 0)
		fill_flags(&(*next), &(*stack_b));
	frst_algbig(&(*next), &(*stack_a), &(*stack_b));
	while ((*stack_a)->flag != 1)
		scnd_algbig(&(*next), &(*stack_a), &(*stack_b));
}
