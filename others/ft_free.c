/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkenned <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 19:47:37 by fkenned           #+#    #+#             */
/*   Updated: 2021/08/07 19:47:39 by fkenned          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	fresh_stack(t_list **stack)
{
	t_list	*p;

	p = *stack;
	if (stack_counter(&(*stack)) > 1)
	{
		while (*stack)
		{
			while (p->next != *stack)
				p = p->next;
			p->next = (*stack)->next;
			free(*stack);
			*stack = p;
			if (p->next == *stack)
			{
				free(p);
				break ;
			}
		}
	}
	else
		free(p);
	*stack = NULL;
}

void	ft_free(t_list **stack)
{
	if (*stack)
		fresh_stack(&(*stack));
}
