/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 13:56:17 by sdummett          #+#    #+#             */
/*   Updated: 2021/02/15 12:26:25 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int *ft_range(int min, int max)
{
	int size;
	int *tab = NULL;
	int i;

	if (min >= max)
		return (tab);
	else
	{
		size = max - (min);
		tab = (int *)malloc(sizeof(int) * size );
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
int main()
{
	int min = -1;
	int max = 5;
	
	ft_range(min, max);
}