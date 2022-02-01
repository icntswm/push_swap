#include "../push_swap.h"

void	ft_sa(t_next *next, t_list **stack_a)
{
	int	save_val;
	int	save_pos;
	int	save_flag;

	save_flag = (*stack_a)->flag;
	save_val = (*stack_a)->value;
	save_pos = (*stack_a)->pos;
	(*stack_a)->flag = (*stack_a)->next->flag;
	(*stack_a)->value = (*stack_a)->next->value;
	(*stack_a)->pos = (*stack_a)->next->pos;
	(*stack_a)->next->flag = save_flag;
	(*stack_a)->next->value = save_val;
	(*stack_a)->next->pos = save_pos;
	save_finish_str(&(*next), "sa\n");
}

void	ft_sb(t_next *next, t_list **stack_b)
{
	int	save_val;
	int	save_pos;
	int	save_flag;

	save_flag = (*stack_b)->flag;
	save_val = (*stack_b)->value;
	save_pos = (*stack_b)->pos;
	(*stack_b)->flag = (*stack_b)->next->flag;
	(*stack_b)->value = (*stack_b)->next->value;
	(*stack_b)->pos = (*stack_b)->next->pos;
	(*stack_b)->next->flag = save_flag;
	(*stack_b)->next->value = save_val;
	(*stack_b)->next->pos = save_pos;
	save_finish_str(&(*next), "sb\n");
}

void	ft_ss(t_next *next, t_list **stack_a, t_list **stack_b)
{
	ft_sa(&(*next), &(*stack_a));
	ft_sb(&(*next), &(*stack_b));
	save_finish_str(&(*next), "ss\n");
}
