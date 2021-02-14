/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 17:12:09 by sdummett          #+#    #+#             */
/*   Updated: 2021/02/14 17:12:27 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (0);
}

void	add_condition(int tab[6][6], char *param[])
{
	tab[0][1] = param[1][0] - 48;
	tab[0][2] = param[1][2] - 48;
	tab[0][3] = param[1][4] - 48;
	tab[0][4] = param[1][6] - 48;
	tab[5][1] = param[1][8] - 48;
	tab[5][2] = param[1][10] - 48;
	tab[5][3] = param[1][12] - 48;
	tab[5][4] = param[1][14] - 48;
	tab[1][0] = param[1][16] - 48;
	tab[2][0] = param[1][18] - 48;
	tab[3][0] = param[1][20] - 48;
	tab[4][0] = param[1][22] - 48;
	tab[1][5] = param[1][24] - 48;
	tab[2][5] = param[1][26] - 48;
	tab[3][5] = param[1][28] - 48;
	tab[4][5] = param[1][30] - 48;
}

int		input_check(char *param[])
{
	int i;

	i = 0;
	while (param[1] != 0 && i != 31)
	{
		if (param[1][i] >= '1' && param[1][i] <= '4' && i % 2 == 0)
			i++;
		else if (param[1][i] == ' ' && i % 2 != 0)
			i++;
		else
			return (0);
	}
	if (i != 31)
		return (0);
	else
		return (1);
}

void	ft_tab_initializer(int tab[6][6])
{
	int i;
	int j;

	i = 0;
	while (i < 6)
	{
		j = 0;
		while (j < 6)
		{
			tab[i][j] = 0;
			j++;
		}
		i++;
	}
}

int		main(int argc, char *argv[])
{
	int tab[6][6];

	if (argc != 2)
	{
		ft_putstr("Error\n", 6);
		return (0);
	}
	ft_tab_initializer(tab);
	if (input_check(&argv[0]))
	{
		add_condition(tab, &argv[0]);
		ft_main(tab);
	}
	else
	{
		ft_putstr("Error\n", 6);
		return (0);
	}
	if (tab[0][0] == 0)
		ft_putstr("Error\n", 6);
	return (0);
}
