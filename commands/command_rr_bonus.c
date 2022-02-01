#include "../push_swap.h"

void	ft_ra_bonus(t_list **stack_a)
{
	*stack_a = (*stack_a)->next;
}

void	ft_rb_bonus(t_list **stack_b)
{
	*stack_b = (*stack_b)->next;
}

void	ft_rr_bonus(t_list **stack_a, t_list **stack_b)
{
	ft_ra_bonus(&(*stack_a));
	ft_rb_bonus(&(*stack_b));
}
