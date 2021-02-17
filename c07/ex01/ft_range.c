/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 13:56:17 by sdummett          #+#    #+#             */
/*   Updated: 2021/02/17 14:47:39 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int size;
	int *tab;
	int i;

	if (min >= max)
	{
		tab = 0;
		return (tab);
	}
	else
	{
		size = max - (min);
		if (!(tab = (int *)malloc(sizeof(int) * size)))
			return (0);
		i = 0;
		while (i < size)
		{
			tab[i] = min;
			min++;
			i++;
		}
	}
	return (tab);
}
