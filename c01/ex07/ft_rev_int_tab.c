/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 08:28:31 by sdummett          #+#    #+#             */
/*   Updated: 2021/02/04 08:28:33 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void ft_rev_int_tab(int *tab, int size)
{
	int temp;
	int i = 0;
	
	while(i < size)
	{
		temp = tab[size];
		tab[size] = tab[i];
		tab[i] = temp;
		size--;
		i++;
	}

}

int main()
{
	int i = 0;
	int size = 16;
	int tab[size];

	for(i = 0; i < size; i++)
	{
		tab[i] = i + 100;
	}
	
	i = 0;
	while (i < size)
	{
		printf("Before calling function: tab[%d] = %d\n", i, tab[i]);
		i++;
	}

	ft_rev_int_tab(tab, size - 1);
	
	i = 0;
	while (i < size)
	{
		printf("After calling function: tab[%d] = %d\n", i, tab[i]);
		i++;
	}
	
}
