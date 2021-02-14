/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolver_bis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 17:11:59 by sdummett          #+#    #+#             */
/*   Updated: 2021/02/14 17:12:01 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_header2.h"

void	ft_recursive_bis(int tab[6][6], int line, int column)
{
	int i;

	i = 1;
	while (i < 5)
	{
		tab[line][column] = i;
		if (ft_valid_test(tab, line, column))
		{
			if (line == 4)
			{
				if (ft_vertical_verif(tab, column))
					ft_recursive(tab, line, column + 1);
			}
			else
				ft_recursive(tab, line, column + 1);
		}
		i++;
	}
}

int		ft_vertical_verif_bottom(int tab[6][6], int column)
{
	int value;

	value = 1;
	if (tab[4][column] < tab[3][column])
		value++;
	if (tab[2][column] > tab[4][column] && tab[2][column] > tab[3][column])
		value++;
	if (tab[1][column] > tab[4][column] && tab[1][column] > tab[3][column]
	&& tab[1][column] > tab[2][column])
		value++;
	if (tab[5][column] == value)
		return (1);
	else
		return (0);
}

int		ft_vertical_verif(int tab[6][6], int column)
{
	int value;

	value = 1;
	if (tab[1][column] < tab[2][column])
		value++;
	if (tab[3][column] > tab[1][column] && tab[3][column] > tab[2][column])
		value++;
	if (tab[4][column] > tab[1][column] && tab[4][column] > tab[2][column]
	&& tab[4][column] > tab[3][column])
		value++;
	if (tab[0][column] == value)
		return (ft_vertical_verif_bottom(tab, column));
	else
		return (0);
}

int		ft_horizontal_verif_right(int tab[6][6], int line)
{
	int value;

	value = 1;
	if (tab[line][4] < tab[line][3])
		value++;
	if (tab[line][2] > tab[line][4] && tab[line][2] > tab[line][3])
		value++;
	if (tab[line][1] > tab[line][4] && tab[line][1] > tab[line][3]
	&& tab[line][1] > tab[line][2])
		value++;
	if (tab[line][5] == value)
		return (1);
	else
		return (0);
}

int		ft_horizontal_verif(int tab[6][6], int line)
{
	int value;

	value = 1;
	if (tab[line][1] < tab[line][2])
		value++;
	if (tab[line][3] > tab[line][1] && tab[line][3] > tab[line][2])
		value++;
	if (tab[line][4] > tab[line][1] && tab[line][4] > tab[line][2]
	&& tab[line][4] > tab[line][3])
		value++;
	if (tab[line][0] == value)
		return (ft_horizontal_verif_right(tab, line));
	else
		return (0);
}
