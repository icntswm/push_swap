#include "../push_swap.h"

void	ft_ra(t_next *next, t_list **stack_a)
{
	*stack_a = (*stack_a)->next;
	save_finish_str(&(*next), "ra\n");
}

void	ft_rb(t_next *next, t_list **stack_b)
{
	*stack_b = (*stack_b)->next;
	save_finish_str(&(*next), "rb\n");
}

void	ft_rr(t_next *next, t_list **stack_a, t_list **stack_b)
{
	ft_ra(&(*next), &(*stack_a));
	ft_rb(&(*next), &(*stack_b));
	save_finish_str(&(*next), "rr\n");
}
