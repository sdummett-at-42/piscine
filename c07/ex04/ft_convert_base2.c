/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 19:47:09 by sdummett          #+#    #+#             */
/*   Updated: 2021/02/22 19:45:49 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_base_is_ok(char *base)
{
	int			i;
	int			j;

	if (*base == 0)
		return (1);
	i = 0;
	while (base[i])
	{
		if (base[i] == '-' || base[i] == '+' || base[i] == '\f' || base[i] == '\t' || base[i] == ' ' || base[i] == '\n' || base[i] == '\r' || base[i] == '\v' || base[i] < 32 || base[i] == 127)
			return (1);
		j = 0;
		while (base[j])
		{
			if (i == j)
				j++;
			else if (base[j] == base[i])
				return (1);
			else
				j++;
		}
		i++;
	}
	return (0);
}

int		ft_strlen(char *str)
{
	int			i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_put_base(int *tab, int tab_size, int sign, char *base)
{
	int			i;
	char		*str;

	if (!(str = (char *)malloc(sizeof(char) * tab_size + sign + 1)))
		return (0);
	i = 0;
	if (sign == 1)
	{
		str[i] = '-';
		i++;
	}
	while (tab_size > 0)
	{
		str[i] = base[tab[tab_size - 1]];
		tab_size--;
		i++;
	}
	str[i] = '\0';
	return (str);
}
