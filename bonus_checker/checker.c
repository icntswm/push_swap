/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkenned <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 19:40:41 by fkenned           #+#    #+#             */
/*   Updated: 2021/08/07 19:40:42 by fkenned          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	zapis(char **array)
{
	int		i;
	int		l;
	int		r;
	char	c;
	char	*tmp;

	r = 0;
	l = 1;
	*array = malloc(l);
	(*array)[0] = '\0';
	while ((read(0, &c, 1) > 0) && l++ && c != '\n')
	{
		r++;
		tmp = malloc(l);
		i = -1;
		while (++i < l - 2)
			tmp[i] = (*array)[i];
		tmp[i] = c;
		tmp[i + 1] = '\0';
		free(*array);
		*array = tmp;
	}
	return (r);
}

void	result(int argc, t_list **stack_a)
{
	if (error_sortlist(&(*stack_a)) == 1
		&& stack_counter(&(*stack_a)) == argc - 1)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

void	ft_bonus(int argc, char **argv, t_list **stack_a, t_list **stack_b)
{
	char	*array[N];
	int		n;

	n = 0;
	error_search(argc, argv, &(*stack_a), 1);
	while (zapis(&array[n]) > 0)
		n++;
	error_command(n, &(*array));
	exec_cmd(n, &(*stack_a), &(*stack_b), &(*array));
	result(argc, &(*stack_a));
	ft_free(&(*stack_a));
	ft_free(&(*stack_b));
	while (n > 0)
	{
		free(array[n]);
		n--;
	}
	free(*array);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		i;

	stack_a = NULL;
	stack_b = NULL;
	i = 1;
	while (i < argc)
	{
		stack_a = add_item(&stack_a, ft_atoi(argv[i]));
		i++;
		if (i == argc)
			stack_a = stack_a->next;
	}
	if (stack_a)
		ft_bonus(argc, argv, &stack_a, &stack_b);
	return (0);
}
