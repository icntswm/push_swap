#include "../push_swap.h"

int	check_error(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	if (argc == 1)
		return (1);
	else if (argc == 2)
		return (3);
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if ((argv[i][j] >= '0' && argv[i][j] <= '9') || argv[i][j] == '-')
				j++;
			else
				return (2);
		}
		i++;
	}
	return (0);
}

int	error_numstr(int argc, char **argv)
{
	if (check_error(argc, argv) == 1
		|| check_error(argc, argv) == 2
		|| check_error (argc, argv) == 3)
	{
		if (check_error(argc, argv) == 1)
			return (1);
		else if (check_error(argc, argv) == 2)
			return (2);
		else if (check_error (argc, argv) == 3)
			return (3);
	}
	return (0);
}

int	error_sortlist(t_list **stack_a)
{
	t_list	*p;
	int		i;
	int		save_value;
	int		col;

	col = 1;
	p = *stack_a;
	i = 1;
	while (p->next != *stack_a)
	{
		p = p->next;
		col++;
	}
	p = p->next;
	while (p->next != *stack_a)
	{
		save_value = p->value;
		p = p->next;
		if (p->value > save_value)
			i++;
	}
	if (i == col)
		return (1);
	return (0);
}

int	check_dublicat(t_list **stack_a, int num)
{
	t_list	*p2;
	int		count;

	p2 = *stack_a;
	count = 0;
	while (p2->next != *stack_a)
	{
		if (p2->value == num)
		{
			count++;
			if (count > 1)
				return (1);
		}
		p2 = p2->next;
		if (p2->next == *stack_a)
		{
			if (p2->value == num)
			{
				count++;
				if (count > 1)
					return (1);
			}
		}
	}
	return (0);
}

int	error_dublicat(t_list **stack_a)
{
	t_list	*p1;
	int		num;

	p1 = *stack_a;
	num = p1->value;
	while (p1->next != *stack_a)
	{
		if (check_dublicat(&(*stack_a), num) == 1)
			return (1);
		p1 = p1->next;
		num = p1->value;
	}
	return (0);
}
