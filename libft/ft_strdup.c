/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkenned <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 19:45:55 by fkenned           #+#    #+#             */
/*   Updated: 2021/08/07 19:45:56 by fkenned          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	*ft_strdup(char *str)
{
	int		i;
	int		lenght;
	char	*cop;

	i = 0;
	lenght = ft_strlen(str);
	cop = (char *)malloc(sizeof(char) * (lenght + 1));
	if (!cop)
		return (NULL);
	while (str[i])
	{
		cop[i] = str[i];
		i++;
	}
	cop[i] = '\0';
	return (cop);
}
