/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 12:27:00 by sdummett          #+#    #+#             */
/*   Updated: 2021/02/17 15:04:19 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	int size;
	int *tab;
	int i;

	if (min >= max)
		return (0);
	size = max - (min);
	if (!(tab = (int *)malloc(sizeof(int) * size)))
		return (-1);
	i = 0;
	while (i < size)
	{
		tab[i] = min;
		min++;
		i++;
	}
	*range = tab;
	return (size);
}
