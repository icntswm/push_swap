/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg45.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkenned <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 19:36:31 by fkenned           #+#    #+#             */
/*   Updated: 2021/08/07 19:36:32 by fkenned          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	alg5(t_next *next, t_list **stack_a, t_list **stack_b)
{
	t_list	*p;

	p = *stack_a;
	while (p->next != *stack_a)
	{
		if (p->pos == 1 || p->pos == 2)
		{
			*stack_a = p;
			ft_pb(&(*next), &(*stack_a), &(*stack_b));
			p = *stack_a;
			if (stack_counter(&(*stack_b)) == 2)
				break ;
		}
		else
		{
			ft_ra(&(*next), &(*stack_a));
			p = *stack_a;
		}
	}
	if (error_sortlist(&(*stack_a)) == 0)
		alg23(&(*next), &(*stack_a));
	if ((*stack_b)->pos < (*stack_b)->next->pos)
		ft_sb(&(*next), &(*stack_b));
	while (stack_counter(&(*stack_a)) != 5)
		ft_pa(&(*next), &(*stack_b), &(*stack_a));
}

void	alg4(t_next *next, t_list **stack_a, t_list **stack_b)
{
	t_list	*p;

	p = *stack_a;
	while (p->next != *stack_a)
	{
		if (p->pos == 1)
		{
			*stack_a = p;
			ft_pb(&(*next), &(*stack_a), &(*stack_b));
			p = *stack_a;
			if (stack_counter(&(*stack_b)) == 1)
				break ;
		}
		else
		{
			ft_ra(&(*next), &(*stack_a));
			p = *stack_a;
		}
	}
	if (error_sortlist(&(*stack_a)) == 0)
		alg23(&(*next), &(*stack_a));
	ft_pa(&(*next), &(*stack_b), &(*stack_a));
}

void	alg45(t_next *next, t_list **stack_a, t_list **stack_b)
{
	if (next->save_argc == 5)
		alg4(&(*next), &(*stack_a), &(*stack_b));
	else if (next->save_argc == 6)
		alg5(&(*next), &(*stack_a), &(*stack_b));
}
