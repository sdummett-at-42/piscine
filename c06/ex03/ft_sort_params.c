/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 15:14:48 by sdummett          #+#    #+#             */
/*   Updated: 2021/02/10 15:14:51 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void ft_putstr(char *str, int str_len)
{
	write(1, str, str_len);
}

int ft_strcmp(char *s1, char *s2)
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

int	main(int argc, char *argv[])
{
	int i;
	int j;
	int tab[argc];

	if (argc == 1)
		return (0);
	if (argc == 2)
	{
		ft_putstr(argv[1], ft_strlen(argv[1]));
		return (0);
	}
	i = 0;
	while (i < argc - 1)
	{
		if (ft_strcmp(argv[i + 1], argv[i + 2]) > 0)
		{
			j = 0;
			tab[j] = i + 2;;
			j++;
			i = 0;
		}
		else
		{
			tab[j] = i + 1;
			j++;
			i++;
		}
	}
	tab[j] = i;
	i = 1;
	while (i <= argc )
	{
		ft_putstr(argv[tab[i]], ft_strlen(argv[tab[i]]));
		i++;
	}
	return (0);
}
