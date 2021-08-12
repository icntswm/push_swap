/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_for_first_part.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkenned <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 19:37:37 by fkenned           #+#    #+#             */
/*   Updated: 2021/08/07 19:37:39 by fkenned          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	push_in_a_frst(t_next *next, t_list **stack_b, t_list **stack_a)
{
	t_list	*p;

	p = *stack_b;
	if (p->pos <= next->mid_b && p->pos != next->next_el)
	{
		ft_pa(&(*next), &(*stack_b), &(*stack_a));
		(*stack_a)->flag = next->flag;
		p = *stack_b;
	}
	else if ((*stack_b)->pos == next->next_el)
	{
		ft_pa(&(*next), &(*stack_b), &(*stack_a));
		(*stack_a)->flag = 1;
		ft_ra(&(*next), &(*stack_a));
		next->next_el++;
		next->push_more++;
	}
	else
	{
		(*stack_b)->flag = next->flag + 1;
		ft_rb(&(*next), &(*stack_b));
		p = *stack_b;
	}
}

void	push_a_frst_alg(t_next *next, t_list **stack_a, t_list **stack_b)
{
	while (check_posit_a(next->mid_b, &(*stack_b)) != 0
		&& next->save_flag_in_b == (*stack_b)->flag)
	{
		push_in_a_frst(&(*next), &(*stack_b), &(*stack_a));
		while (check_swap(&(*next), &(*stack_a), &(*stack_b)) > 0)
		{
		}
	}
}

void	prt1_frst(t_next *next, t_list **stack_a, t_list **stack_b)
{
	next->mid_a = search_mid_a(&(*next), &(*stack_a));
	next->push_less = next->mid_a;
	next->save_flag_in_a = (*stack_a)->flag;
	while ((*stack_a)->flag == next->save_flag_in_a)
		push_in_b(&(*next), &(*stack_a), &(*stack_b));
	next->flag = next->flag + 2;
	next->pos_nextel_b = search_pos_next_in_b(&(*next), &(*stack_b));
	if (check_last_flag_in_a(&(*stack_a)) != next->next_el - 1)
	{
		while (check_last_flag_in_a(&(*stack_a)) != next->next_el - 1)
			ft_rra(&(*next), &(*stack_a), 0);
	}
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
}

void	prt2_frst(t_next *next, t_list **stack_a, t_list **stack_b)
{
	next->mid_b = search_mid_a(&(*next), &(*stack_b));
	next->flag = next->flag + 2;
	next->pos_nextel_b = search_pos_next_in_b(&(*next), &(*stack_b));
	if (check_last_flag_in_a(&(*stack_a)) != next->next_el - 1)
	{
		while (check_last_flag_in_a(&(*stack_a)) != next->next_el - 1)
			ft_rra(&(*next), &(*stack_a), 0);
	}
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
}
