/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 14:59:38 by sdummett          #+#    #+#             */
/*   Updated: 2021/02/13 16:45:16 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (0);
}

void ft_putstr(char *str, int strlen)
{
	write(1, str, strlen);
}
int main(int argc, char *argv[])
{
	int value_tab[6][6];
	int i;
	int j;

	if (argc != 2)
	{
		ft_putstr("Error\n", 6);
		return (0);
	}
	i = 0;
	while (i < 4)
	{
		j = 0;
		while(j < 4)
		{
			value_tab[i][j] = 0;
			j++;
		}
		i++;
	}
	i = 0;
	while (i < 4)
	{
		j = 0;
		while(j < 4)
		{
			printf("tab[%d][%d]:%d\n", i, j, value_tab[i][j]);
			j++;
		}
		i++;
	}
	ft_display(tab);	
	return (0);

}

void ft_display(char *tab[])
{
	int i;
	int j;
	int k;
	char str_display[8];
	i = 0;
	while (i < 4)
	{
		j = 0;
		k = 0;
		while (j < 4)
		{
			str_display[k] = tab[i][j] + 48;
			str_display[k + 1] = ' ';
			k = k + 2;
			j++;
		}
		str_display[k - 1] = '\0';
		ft_putstr(str_display, ft_strlen(str_display));
		i++;
	}
}
