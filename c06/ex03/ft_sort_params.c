/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 15:14:48 by sdummett          #+#    #+#             */
/*   Updated: 2021/02/12 15:14:11 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr(char *str, int str_len)
{
	write(1, str, str_len);
	write(1, "\n", 1);
}

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] != 0)
	{
		if (s2[i] == 0)
			return (s1[i]);
		if (s1[i] > s2[i] || s2[i] > s1[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

void	ft_sort_params(char *param[], int *tab, int tab_size)
{
	int i;
	int temp;

	i = 0;
	while (i < tab_size)
	{
		tab[i] = i;
		i++;
	}
	i = 1;
	while (i < tab_size - 1)
	{
		if (ft_strcmp(param[tab[i]], param[tab[i + 1]]) > 0)
		{
			temp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = temp;
			i = 1;
		}
		else
			i++;
	}
}

int		main(int argc, char *argv[])
{
	int i;
	int tab[argc];

	if (argc == 1)
		return (0);
	if (argc == 2)
	{
		ft_putstr(argv[1], ft_strlen(argv[1]));
		return (0);
	}
	ft_sort_params(&argv[0], tab, argc);
	i = 1;
	while (i < argc)
	{
		ft_putstr(argv[tab[i]], ft_strlen(argv[tab[i]]));
		i++;
	}
	return (0);
}
