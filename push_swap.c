#include "push_swap.h"

void	make_stack_a(int argc, char **argv, t_list **stack_a)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (i < argc)
			*stack_a = add_item(&(*stack_a), ft_atoi(argv[i]));
		i++;
		if (i == argc)
			*stack_a = (*stack_a)->next;
	}
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_next	next;

	stack_a = NULL;
	stack_b = NULL;
	make_stack_a(argc, argv, &stack_a);
	if (stack_a)
	{
		error_search(argc, argv, &stack_a, 0);
		make_sort_position(argc, &stack_a);
		sel_alg(argc, &stack_a, &stack_b, &next);
		print_sortlist(&next);
		ft_free(&stack_a);
		ft_free(&stack_b);
	}
	return (0);
}
