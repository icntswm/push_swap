#include "../../push_swap.h"

void	ft_scroll(t_next *next, t_list **stack_a, t_list **stack_b)
{
	while ((*stack_b)->pos != next->next_el)
	{
		if (check_last_flag_in_a(&(*stack_a)) == next->next_el - 1)
			break ;
		else
			ft_rrr(&(*next), &(*stack_a), &(*stack_b));
	}
	if (check_last_flag_in_a(&(*stack_a)) == next->next_el - 1)
	{
		if (next->pos_nextel_b > next->size_stack_b + 1)
		{
			while ((*stack_b)->pos != next->next_el)
				ft_rrb(&(*next), &(*stack_b), 0);
		}
		else
		{
			while ((*stack_b)->pos != next->next_el)
				ft_rb(&(*next), &(*stack_b));
		}
	}
	else if ((*stack_b)->pos == next->next_el)
	{
		while (check_last_flag_in_a(&(*stack_a)) != next->next_el - 1)
			ft_rra(&(*next), &(*stack_a), 0);
	}
}

void	ft_scroll_next_in_b(t_next *next, t_list **stack_b)
{
	if (next->pos_nextel_b > next->size_stack_b + 1)
	{
		while ((*stack_b)->pos != next->next_el)
			ft_rrb(&(*next), &(*stack_b), 0);
	}
	else
	{
		while ((*stack_b)->pos != next->next_el)
			ft_rb(&(*next), &(*stack_b));
	}
}

void	push_lst_elm(t_next *next, t_list **stack_a, t_list **stack_b)
{
	if (stack_counter(&(*stack_a)) != next->save_argc - 1)
	{
		while (stack_counter(&(*stack_a)) != next->save_argc - 1)
		{
			ft_pa(&(*next), &(*stack_b), &(*stack_a));
			while (check_swap(&(*next), &(*stack_a), &(*stack_b)) > 0)
			{
			}
		}
	}
	else
	{
		while (check_swap(&(*next), &(*stack_a), &(*stack_b)) > 0)
		{
		}
	}
}

void	scnd_algbig(t_next *next, t_list **stack_a, t_list **stack_b)
{
	next->save_flag_in_a = (*stack_a)->flag;
	next->max_b = 0;
	next->mid_a = search_mid_a(&(*next), &(*stack_a));
	next->push_less = next->mid_a;
	while ((*stack_a)->flag == next->save_flag_in_a)
		push_in_b(&(*next), &(*stack_a), &(*stack_b));
	next->pos_nextel_b = search_pos_next_in_b(&(*next), &(*stack_b));
	next->size_stack_b = stack_counter(&(*stack_b)) / 2;
	if (check_last_flag_in_a(&(*stack_a)) != next->next_el - 1)
		ft_scroll(&(*next), &(*stack_a), &(*stack_b));
	else
		ft_scroll_next_in_b(&(*next), &(*stack_b));
	next->mid_b = (next->max_b - next->next_el) / 2 + next->next_el;
	next->flag = next->flag + 2;
	while (check_posit_b(next->mid_b, &(*stack_b)) != 0)
		push_in_a_scnd(&(*next), &(*stack_b), &(*stack_a));
	if (check_posit_b(next->mid_b, &(*stack_b)) == 0
		&& (*stack_b)->pos >= next->mid_b)
	{
		ft_pa(&(*next), &(*stack_b), &(*stack_a));
		(*stack_a)->flag = next->flag;
	}
	else if (check_posit_b(next->mid_b, &(*stack_b)) == 0)
		fill_flags(&(*next), &(*stack_b));
	push_lst_elm(&(*next), &(*stack_a), &(*stack_b));
}
