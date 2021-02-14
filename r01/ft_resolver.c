/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 14:59:38 by sdummett          #+#    #+#             */
/*   Updated: 2021/02/14 17:11:42 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_header.h"

void	ft_putstr(char *str, int strlen)
{
	write(1, str, strlen);
}

void	ft_display(int tab[6][6])
{
	int	i;
	int	j;

	if (tab[0][0] == 0)
	{
		i = 1;
		while (i < 5)
		{
			j = 1;
			while (j < 5)
			{
				ft_putchar(tab[i][j] + 48);
				j++;
			}
			ft_putstr("\n", 1);
			i++;
		}
	}
	tab[0][0] = 1;
}

int		ft_valid_test(int tab[6][6], int line, int column)
{
	int	i;

	i = 1;
	while (i < column)
	{
		if (tab[line][column] == tab[line][i])
			return (0);
		i++;
	}
	i = 1;
	while (i < line)
	{
		if (tab[line][column] == tab[i][column])
			return (0);
		i++;
	}
	return (1);
}

void	ft_recursive(int tab[6][6], int line, int column)
{
	if (column < 5)
		ft_recursive_bis(tab, line, column);
	else if (line < 4)
	{
		if (ft_horizontal_verif(tab, line))
			ft_recursive(tab, line + 1, 1);
	}
	else
	{
		if (ft_horizontal_verif(tab, line))
			ft_display(tab);
	}
}

void	ft_main(int tab[6][6])
{
	int	i;

	i = 1;
	while (i < 5)
	{
		tab[1][1] = i;
		ft_recursive(tab, 1, 2);
		i++;
	}
}
