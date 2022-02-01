#include "../push_swap.h"

void	*add_item(t_list **stack_a, long long num)
{
	t_list	*temp;
	void	*p;

	temp = NULL;
	if ((*stack_a) == NULL)
	{
		*stack_a = (t_list *)malloc(sizeof(t_list));
		(*stack_a)->value = num;
		(*stack_a)->pos = 0;
		(*stack_a)->flag = 0;
		(*stack_a)->next = (*stack_a);
		return (*stack_a);
	}
	else if ((*stack_a))
	{
		temp = (t_list *)malloc(sizeof(t_list));
		p = (*stack_a)->next;
		(*stack_a)->next = temp;
		temp->value = num;
		temp->pos = 0;
		temp->flag = 0;
		temp->next = p;
	}
	return (temp);
}
