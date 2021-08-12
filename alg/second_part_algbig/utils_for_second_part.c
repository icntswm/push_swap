/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_for_second_part.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkenned <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 19:38:15 by fkenned           #+#    #+#             */
/*   Updated: 2021/08/07 19:38:17 by fkenned          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	push_in_a_scnd(t_next *next, t_list **stack_b, t_list **stack_a)
{
	t_list	*p;

	p = *stack_b;
	if (p->pos >= next->mid_b && p->pos != next->next_el)
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
