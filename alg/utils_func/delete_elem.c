/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_elem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkenned <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 19:38:59 by fkenned           #+#    #+#             */
/*   Updated: 2021/08/07 19:39:01 by fkenned          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	*delete_elem(t_list **stack_a)
{
	t_list	*p;

	p = *stack_a;
	if (p->next == *stack_a)
	{
		p->next = NULL;
		*stack_a = p;
		free(p);
		return (NULL);
	}
	else
	{
		while (p->next != *stack_a)
			p = p->next;
		p->next = (*stack_a)->next;
		free(*stack_a);
		*stack_a = p;
	}
	return (*stack_a);
}
