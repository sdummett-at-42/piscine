/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 20:17:53 by sdummett          #+#    #+#             */
/*   Updated: 2021/02/22 20:26:10 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int *ft_map(int *tab, int length, int(*f)(int))
{
	int i;
	int *array;

	if (!(array = (int *)malloc(sizeof(int) * length)))
		return (0);
	i = 0;
	while (i < length)
	{
		array[i] = f(tab[i]);
		i++;
	}
	return (array);
}
