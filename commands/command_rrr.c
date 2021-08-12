/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_rrr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkenned <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 19:44:12 by fkenned           #+#    #+#             */
/*   Updated: 2021/08/07 19:44:14 by fkenned          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_rra(t_next *next, t_list **stack_a, int check)
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
	if (check == 0)
		save_finish_str(&(*next), "rra\n");
}

void	ft_rrb(t_next *next, t_list **stack_b, int check)
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
	if (check == 0)
		save_finish_str(&(*next), "rrb\n");
}

void	ft_rrr(t_next *next, t_list **stack_a, t_list **stack_b)
{
	ft_rra(&(*next), &(*stack_a), 1);
	ft_rrb(&(*next), &(*stack_b), 1);
	save_finish_str(&(*next), "rrr\n");
}
