/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 08:28:43 by sdummett          #+#    #+#             */
/*   Updated: 2021/02/04 08:28:52 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void ft_sort_int_tab(int *tab, int size)
{
	int temp;
	
	int i = 0;
	while (i < size)
	{
		if (tab[i] < tab[i + 1])
		{
			i++;
		}
		else
		{
			temp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = temp;
			i = 0;
		}
	}
}

int main()
{
	int size = 5;
	int tab[] = {42 ,242, 6, 34, -1};

	for (int i = 0; i < size; i++)
	{
		printf("Before calling function: tab[%d] = %d\n", i, tab[i]);
	}
	ft_sort_int_tab(tab, size);
	for (int i = 0; i < size; i++)
	{
		printf("After calling function: tab[%d] = %d\n", i, tab[i]);
	}
}
