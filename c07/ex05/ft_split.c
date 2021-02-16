/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 12:37:23 by sdummett          #+#    #+#             */
/*   Updated: 2021/02/16 17:18:18 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int ft_strlen(char *str)
{
	int len;

	len = 0;
	while (str[len] != 0)
		len++;
	return (len);
}

void ft_sort_tab(int *tab, int size)
{
	int i;
	int temp;

	i = 0;
	while (i < size - 1)
	{
		if (tab[i] > tab[i + 1])
		{
			temp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = temp;
			i = 0;
		}
		i++;
	}
}

int **ft_split(char *str, char *charset)
{
	int i;
	int j;
	int k;
	int len;
	int *tab;

	tab = (int *)malloc(sizeof(int) * ft_strlen(str));
	i = 0;
	k = 0;
	len = 0;
	while (charset[i] != 0)
	{
		j = 0;
		while (str[j] != 0)
		{
			if (str[j] == charset[i])
			{
				tab[k] = j;
				k++;
			}
			j++;
		}
		i++;
		if ( charset[i] == 0 && str[j] != 0)
			i = 0;
	}
	ft_sort_tab(tab, k);
	i = 0;
	while (i < k)
	{
		printf("tab[%d]:%d\n", i, tab[i]);
		i++;
	}
 	i = 0;
	j = 0;
	printf("ftstrlen:%d, k:%d\n", ft_strlen(str), k);
	while (i < k)	
	{
		if (tab[i] == tab[i + 1] - 1)
			i++;
		else
		{
			len++;
			i++;
		}
		if (i  == k && tab[i - 1] + 1  != ft_strlen(str))
			len++;
	}
	printf("len:%d\n", len);
	return (0);

}

int main()
{
	int **tab;
	char charset[] = " ,";
	char str[] = "Hello  ,World coucou, yo  y,   yy ,, test";
	//char str2[] = "  ";
	//int i;
	//int j;

	tab = ft_split(str, charset);//"Hello world, coucou", " ,"
}
