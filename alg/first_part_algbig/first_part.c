#include "../../push_swap.h"

void	frst_algbig(t_next *next, t_list **stack_a, t_list **stack_b)
{
	while (stack_counter(&(*stack_a)) != next->save_argc - 1)
	{
		while ((*stack_a)->flag != 0)
			prt1_frst(&(*next), &(*stack_a), &(*stack_b));
		if (stack_counter(&(*stack_b)) < 7)
		{
			while (stack_counter(&(*stack_a)) != next->save_argc - 1)
			{
				ft_pa(&(*next), &(*stack_b), &(*stack_a));
				while (check_swap(&(*next), &(*stack_a), &(*stack_b)) > 0)
				{
				}
			}
		}
		else if (stack_counter(&(*stack_b)) != 1)
			prt2_frst(&(*next), &(*stack_a), &(*stack_b));
		if (stack_counter(&(*stack_a)) == next->save_argc - 1)
			break ;
	}
}
