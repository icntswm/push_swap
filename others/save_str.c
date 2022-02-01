#include "../push_swap.h"

void	save_finish_str(t_next *next, char *str)
{
	char	*save;

	if (next->fin_str != NULL)
	{
		save = ft_strjoin(next->fin_str, str);
		free(next->fin_str);
		next->fin_str = save;
	}
	else
		next->fin_str = ft_strdup(str);
}
