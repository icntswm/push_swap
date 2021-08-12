/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_search.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkenned <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 19:45:22 by fkenned           #+#    #+#             */
/*   Updated: 2021/08/07 19:45:23 by fkenned          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_err_cmd(int col, int n, char **m)
{
	if (m[n][0] == 'r' && m[n][1] == 'a' && m[n][2] == '\0')
		col--;
	if (m[n][0] == 'r' && m[n][1] == 'b' && m[n][2] == '\0')
		col--;
	if (m[n][0] == 'r' && m[n][1] == 'r' && m[n][2] == '\0')
		col--;
	if (m[n][0] == 's' && m[n][1] == 'a' && m[n][2] == '\0')
		col--;
	if (m[n][0] == 's' && m[n][1] == 'b' && m[n][2] == '\0')
		col--;
	if (m[n][0] == 's' && m[n][1] == 's' && m[n][2] == '\0')
		col--;
	if (m[n][0] == 'p' && m[n][1] == 'a' && m[n][2] == '\0')
		col--;
	if (m[n][0] == 'p' && m[n][1] == 'b' && m[n][2] == '\0')
		col--;
	if (m[n][0] == 'r' && m[n][1] == 'r' && m[n][2] == 'a' && m[n][3] == '\0')
		col--;
	if (m[n][0] == 'r' && m[n][1] == 'r' && m[n][2] == 'b' && m[n][3] == '\0')
		col--;
	if (m[n][0] == 'r' && m[n][1] == 'r' && m[n][2] == 'r' && m[n][3] == '\0')
		col--;
	return (col);
}

void	error_command(int n, char **array)
{
	int	col;

	col = n;
	while (n > 0)
	{
		n--;
		col = check_err_cmd(col, n, array);
	}
	if (col != n)
	{
		write(1, "Error\n", 6);
		exit (0);
	}
}

int	error_intmax(t_list **stack_a)
{
	t_list	*p;

	p = *stack_a;
	while (p->next != *stack_a)
	{
		if (p->value > INT_MAX || p->value < INT_MIN)
			return (1);
		p = p->next;
		if (p->value > INT_MAX || p->value < INT_MIN)
			return (1);
	}
	return (0);
}

void	error_search(int argc, char **argv, t_list **stack_a, int check)
{
	if (error_numstr(argc, argv) == 1 || error_numstr(argc, argv) == 2
		|| error_numstr(argc, argv) == 3 || error_intmax(&(*stack_a)) == 1
		|| error_dublicat(&(*stack_a)) == 1 || error_sortlist(&(*stack_a)) == 1)
	{
		if (error_numstr(argc, argv) == 1
			|| error_numstr(argc, argv) == 2
			|| error_intmax(&(*stack_a)) == 1
			|| error_dublicat(&(*stack_a)) == 1)
			write(1, "Error\n", 6);
		if (check == 0 || (check == 1 && (error_numstr(argc, argv) == 1
					|| error_numstr(argc, argv) == 2
					|| error_numstr(argc, argv) == 3
					|| error_intmax(&(*stack_a)) == 1
					|| error_dublicat(&(*stack_a)) == 1)))
		{
			ft_free(&(*stack_a));
			exit(0);
		}
	}
}
