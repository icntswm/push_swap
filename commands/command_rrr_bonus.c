/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_rrr_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkenned <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 19:43:58 by fkenned           #+#    #+#             */
/*   Updated: 2021/08/07 19:44:00 by fkenned          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_rra_bonus(t_list **stack_a)
{
	int		j;
	int		i;
	t_list	*p;

	j = 0;
	i = 0;
	p = *stack_a;
	while (p->next != *stack_a)
	{
		j++;
		p = p->next;
	}
	while (i < j)
	{
		*stack_a = (*stack_a)->next;
		i++;
	}
}

void	ft_rrb_bonus(t_list **stack_b)
{
	int		j;
	int		i;
	t_list	*p;

	j = 0;
	i = 0;
	p = *stack_b;
	while (p->next != *stack_b)
	{
		j++;
		p = p->next;
	}
	while (i < j)
	{
		*stack_b = (*stack_b)->next;
		i++;
	}
}

void	ft_rrr_bonus(t_list **stack_a, t_list **stack_b)
{
	ft_rra_bonus(&(*stack_a));
	ft_rrb_bonus(&(*stack_b));
}
