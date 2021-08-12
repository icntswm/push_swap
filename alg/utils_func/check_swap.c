/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkenned <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 19:38:44 by fkenned           #+#    #+#             */
/*   Updated: 2021/08/07 19:38:45 by fkenned          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	ft_pos_next(t_list **stack_a, t_next *next)
{
	ft_sa(&(*next), &(*stack_a));
	(*stack_a)->flag = 1;
	ft_ra(&(*next), &(*stack_a));
	next->next_el++;
	next->push_more++;
}

void	ft_pos_nnext(t_list **stack_a, t_list **stack_b, t_next *next)
{
	ft_pb(&(*next), &(*stack_a), &(*stack_b));
	ft_sa(&(*next), &(*stack_a));
	(*stack_a)->flag = 1;
	ft_ra(&(*next), &(*stack_a));
	next->next_el++;
	next->push_more++;
	ft_pa(&(*next), &(*stack_b), &(*stack_a));
}

void	ft_pos_nnnext(t_list **stack_a, t_list **stack_b, t_next *next)
{
	ft_pb(&(*next), &(*stack_a), &(*stack_b));
	ft_pb(&(*next), &(*stack_a), &(*stack_b));
	ft_sa(&(*next), &(*stack_a));
	(*stack_a)->flag = 1;
	ft_ra(&(*next), &(*stack_a));
	next->next_el++;
	next->push_more++;
	ft_pa(&(*next), &(*stack_b), &(*stack_a));
	ft_pa(&(*next), &(*stack_b), &(*stack_a));
}

void	ft_pos_nnnnext(t_list **stack_a, t_list **stack_b, t_next *next)
{
	ft_pb(&(*next), &(*stack_a), &(*stack_b));
	ft_pb(&(*next), &(*stack_a), &(*stack_b));
	ft_pb(&(*next), &(*stack_a), &(*stack_b));
	ft_sa(&(*next), &(*stack_a));
	(*stack_a)->flag = 1;
	ft_ra(&(*next), &(*stack_a));
	next->next_el++;
	next->push_more++;
	ft_pa(&(*next), &(*stack_b), &(*stack_a));
	ft_pa(&(*next), &(*stack_b), &(*stack_a));
	ft_pa(&(*next), &(*stack_b), &(*stack_a));
}

int	check_swap(t_next *next, t_list **stack_a, t_list **stack_b)
{
	if ((*stack_a)->pos == next->next_el
		|| (*stack_a)->next->pos == next->next_el
		|| (*stack_a)->next->next->pos == next->next_el
		|| (*stack_a)->next->next->next->pos == next->next_el
		|| (*stack_a)->next->next->next->next->pos == next->next_el)
	{
		if ((*stack_a)->pos == next->next_el)
		{
			(*stack_a)->flag = 1;
			ft_ra(&(*next), &(*stack_a));
			next->next_el++;
			next->push_more++;
		}
		if ((*stack_a)->next->pos == next->next_el)
			ft_pos_next(&(*stack_a), &(*next));
		if ((*stack_a)->next->next->pos == next->next_el)
			ft_pos_nnext(&(*stack_a), &(*stack_b), &(*next));
		if ((*stack_a)->next->next->next->pos == next->next_el)
			ft_pos_nnnext(&(*stack_a), &(*stack_b), &(*next));
		if ((*stack_a)->next->next->next->next->pos == next->next_el)
			ft_pos_nnnnext(&(*stack_a), &(*stack_b), &(*next));
		return (1);
	}
	return (0);
}
