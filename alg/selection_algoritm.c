#include "../push_swap.h"

void	sel_alg(int argc, t_list **stack_a, t_list **stack_b, t_next *next)
{
	next->fin_str = NULL;
	next->save_argc = argc;
	if (argc == 4 || argc == 3)
		alg23(&(*next), &(*stack_a));
	else if (argc == 6 || argc == 5)
		alg45(&(*next), &(*stack_a), &(*stack_b));
	else if (argc > 6)
		algbig(&(*next), &(*stack_a), &(*stack_b));
}
