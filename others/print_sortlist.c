/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sortlist.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkenned <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 19:47:51 by fkenned           #+#    #+#             */
/*   Updated: 2021/08/07 19:47:52 by fkenned          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	save_str(t_next *next, int k)
{
	char	*save0;
	char	*save1;
	char	*save2;
	char	*save3;

	save0 = NULL;
	save1 = NULL;
	save2 = NULL;
	save3 = NULL;
	save0 = ft_substr(next->fin_str, 0, k);
	save1 = ft_strjoin(save0, "rr\n");
	free(save0);
	save2 = ft_strdup(&next->fin_str[k + 6]);
	free(next->fin_str);
	save3 = ft_strjoin(save1, save2);
	free(save1);
	free(save2);
	next->fin_str = save3;
}

void	print_sortlist(t_next *next)
{
	int	k;
	int	w;

	k = 0;
	w = 0;
	while (next->fin_str[k])
	{
		if (next->fin_str[k] == 'r' && next->fin_str[k + 1] == 'a'
			&& next->fin_str[k + 2] == '\n' && next->fin_str[k + 3] == 'r'
			&& next->fin_str[k + 4] == 'b' && next->fin_str[k + 5] == '\n')
			save_str(&(*next), k);
		else if (next->fin_str[k] == 'r' && next->fin_str[k + 1] == 'b'
			&& next->fin_str[k + 2] == '\n' && next->fin_str[k + 3] == 'r'
			&& next->fin_str[k + 4] == 'a' && next->fin_str[k + 5] == '\n')
			save_str(&(*next), k);
		k++;
	}
	while (w < ft_strlen(next->fin_str))
	{
		write(1, &next->fin_str[w], 1);
		w++;
	}
	free(next->fin_str);
	next->fin_str = NULL;
}
