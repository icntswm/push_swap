/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg23.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkenned <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 19:36:08 by fkenned           #+#    #+#             */
/*   Updated: 2021/08/07 19:36:14 by fkenned          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	alg23(t_next *next, t_list **stack_a)
{
	t_list	*p;

	if (next->save_argc == 3)
		ft_sa(&(*next), &(*stack_a));
	else
	{
		p = *stack_a;
		if (p->pos > p->next->pos && p->pos > p->next->next->pos)
		{
			ft_ra(&(*next), &(*stack_a));
			if (p->next->pos > p->next->next->pos)
				ft_sa(&(*next), &(*stack_a));
		}
		else if (p->pos > p->next->pos && p->pos < p->next->next->pos)
			ft_sa(&(*next), &(*stack_a));
		else if (p->pos < p->next->pos && p->pos > p->next->next->pos)
			ft_rra(&(*next), &(*stack_a), 0);
		else if (p->pos < p->next->pos && p->pos < p->next->next->pos)
		{
			ft_sa(&(*next), &(*stack_a));
			ft_ra(&(*next), &(*stack_a));
		}
	}
}
