#include "../push_swap.h"

void	ft_swap(t_list **stack)
{
	int	swap_v;
	int	swap_p;
	int	swap_f;

	swap_v = (*stack)->next->value;
	(*stack)->next->value = (*stack)->value;
	(*stack)->value = swap_v;
	swap_p = (*stack)->next->pos;
	(*stack)->next->pos = (*stack)->pos;
	(*stack)->pos = swap_p;
	swap_f = (*stack)->next->flag;
	(*stack)->next->flag = (*stack)->flag;
	(*stack)->flag = swap_f;
}

void	*ft_pb_sec(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;
	void	*p;

	if ((*stack_b) == NULL)
	{
		*stack_b = (t_list *)malloc(sizeof(t_list));
		(*stack_b)->value = (*stack_a)->value;
		(*stack_b)->pos = (*stack_a)->pos;
		(*stack_b)->flag = (*stack_a)->flag;
		(*stack_b)->next = (*stack_b);
	}
	else if ((*stack_b) != NULL)
	{
		temp = (t_list *)malloc(sizeof(t_list));
		p = (*stack_b)->next;
		(*stack_b)->next = temp;
		temp->value = (*stack_a)->value;
		temp->pos = (*stack_a)->pos;
		temp->flag = (*stack_a)->flag;
		temp->next = p;
		ft_swap(&(*stack_b));
	}
	return (*stack_b);
}

void	ft_pb(t_next *next, t_list **stack_a, t_list **stack_b)
{
	*stack_b = ft_pb_sec(&(*stack_a), &(*stack_b));
	*stack_a = delete_elem(&(*stack_a));
	if (*stack_a != NULL)
		*stack_a = (*stack_a)->next;
	save_finish_str(&(*next), "pb\n");
}

void	*ft_pa_sec(t_list **stack_b, t_list **stack_a)
{
	t_list	*temp;
	t_list	*p;

	temp = (t_list *)malloc(sizeof(t_list));
	p = (*stack_a)->next;
	(*stack_a)->next = temp;
	temp->value = (*stack_b)->value;
	temp->pos = (*stack_b)->pos;
	temp->flag = (*stack_b)->flag;
	temp->next = p;
	ft_swap(&(*stack_a));
	return (*stack_a);
}

void	ft_pa(t_next *next, t_list **stack_b, t_list **stack_a)
{
	*stack_a = ft_pa_sec(&(*stack_b), &(*stack_a));
	*stack_b = delete_elem(&(*stack_b));
	if (*stack_b != NULL)
		*stack_b = (*stack_b)->next;
	save_finish_str(&(*next), "pa\n");
}
