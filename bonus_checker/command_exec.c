/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_exec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkenned <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 19:41:28 by fkenned           #+#    #+#             */
/*   Updated: 2021/08/07 19:41:30 by fkenned          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	exec3(int j, t_list **stack_a, t_list **stack_b, char **array)
{
	if (array[j][0] == 'p' && array[j][1] == 'a'
		&& array[j][2] == '\0' && *stack_a && *stack_b)
		ft_pa_bonus(&(*stack_b), &(*stack_a));
	if (array[j][0] == 'p' && array[j][1] == 'b'
		&& array[j][2] == '\0' && *stack_a)
		ft_pb_bonus(&(*stack_a), &(*stack_b));
	if (array[j][0] == 'r' && array[j][1] == 'r'
		&& array[j][2] == 'a' && array[j][3] == '\0' && *stack_a)
		ft_rra_bonus(&(*stack_a));
	if (array[j][0] == 'r' && array[j][1] == 'r'
		&& array[j][2] == 'b' && array[j][3] == '\0' && *stack_b)
		ft_rrb_bonus(&(*stack_b));
	if (array[j][0] == 'r' && array[j][1] == 'r'
		&& array[j][2] == 'r' && array[j][3] == '\0' && *stack_b && *stack_a)
	{
		ft_rra_bonus(&(*stack_a));
		ft_rrb_bonus(&(*stack_b));
	}
}

void	exec2(int j, t_list **stack_a, t_list **stack_b, char **array)
{
	if (array[j][0] == 's' && array[j][1] == 'a'
		&& array[j][2] == '\0' && *stack_a)
		ft_sa_bonus(&(*stack_a));
	if (array[j][0] == 's' && array[j][1] == 'b'
		&& array[j][2] == '\0' && *stack_b)
		ft_sb_bonus(&(*stack_b));
	if (array[j][0] == 's' && array[j][1] == 's'
		&& array[j][2] == '\0' && *stack_b && *stack_a)
	{
		ft_sb_bonus(&(*stack_b));
		ft_sa_bonus(&(*stack_a));
	}
}

void	exec1(int j, t_list **stack_a, t_list **stack_b, char **array)
{
	if (array[j][0] == 'r' && array[j][1] == 'a'
		&& array[j][2] == '\0' && *stack_a)
		ft_ra_bonus(&(*stack_a));
	if (array[j][0] == 'r' && array[j][1] == 'b'
		&& array[j][2] == '\0' && *stack_b)
		ft_rb_bonus(&(*stack_b));
	if (array[j][0] == 'r' && array[j][1] == 'r'
		&& array[j][2] == '\0' && *stack_b && *stack_a)
	{
		ft_rb_bonus(&(*stack_b));
		ft_ra_bonus(&(*stack_a));
	}
}

void	exec_cmd(int n, t_list **stack_a, t_list **stack_b, char **array)
{		
	int	j;

	j = 0;
	while (j <= n)
	{
		exec1(j, &(*stack_a), &(*stack_b), array);
		exec2(j, &(*stack_a), &(*stack_b), array);
		exec3(j, &(*stack_a), &(*stack_b), array);
		j++;
	}
}
