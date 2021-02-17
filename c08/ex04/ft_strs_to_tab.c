/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 21:54:18 by sdummett          #+#    #+#             */
/*   Updated: 2021/02/18 00:30:19 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int		ft_strlen(char *str)
{
	int len;

	len = 0;
	while (str[len] != 0)
		len++;
	return (len);
}

void	ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i] != 0)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int		i;
	t_stock_str	*stock_tab;

	if (!(stock_tab = (t_stock_str *)malloc(sizeof(t_stock_str) * ac + 1)))
		return (0);
	i = 0;
	while (i < ac)
	{
		stock_tab[i].size = ft_strlen(av[i]);
		stock_tab[i].str = av[i];
		if (!(stock_tab[i].copy = (char *)malloc(sizeof(char) *
						ft_strlen(av[i]) + 1)))
			return (0);
		ft_strcpy(stock_tab[i].copy, av[i]);
		i++;
	}
	stock_tab[i].str = 0;
}
