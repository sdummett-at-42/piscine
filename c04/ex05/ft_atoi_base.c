/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 07:38:27 by sdummett          #+#    #+#             */
/*   Updated: 2021/02/10 16:32:50 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

int		ft_base_is_ok(char *base)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (base[i])
	{
		if (base == '\0' || base[i] == '-' || base[i] == '+' ||
			base[i] == ' ' || (base[i] >= 9 && base[i] <= 13))
			return (1);
		c = base[i];
		j = 0;
		while (base[j])
		{
			if (i == j)
				j++;
			else if (base[j] == c)
				return (1);
			else
				j++;
		}
		i++;
	}
	return (0);
}

int		ft_str_is_convertissable(char *str, char *base)
{
	int i;
	int j;
	int match;

	i = 0;
	while (str[i] != 0)
	{
		j = 0;
		match = 0;
		while (base[j] != 0)
		{
			if (base[j] == str[i])
				match++;
			j++;
		}
		if (match == 0)
			return (i);
		i++;
	}
	return (i);
}

int		ft_convert_base(int *tab, char *base, int base_len, char *str)
{
	int i;
	int j;
	int nb;

	i = 0;
	while (i < ft_str_is_convertissable(str, base))
	{
		j = 1;
		while (j <= base_len)
		{
			if (str[i] == tab[j] && i == 0)
				nb = tab[j - 1];
			else if (str[i] == tab[j])
				nb = nb * (base_len / 2) + tab[j - 1];
			j = j + 2;
		}
		i++;
	}
	return (nb);
}

int		ft_atoi_base(char *str, char *base)
{
	int i;
	int j;
	int sign;
	int tab[ft_strlen(base) * 2];

	if (ft_base_is_ok(base) == 1) //|| ft_str_is_convertissable(str, base) == 0)
		return (0);
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	while (*str == '+' || *str  == '-')
		if (*str++  == '-')
			sign *= -1;
	if (ft_str_is_convertissable(str, base) == 0)
		return (0);
	i = 0;
	j = 0;
	while (i < ft_strlen(base) * 2)
	{
		tab[i] = j;
		tab[i + 1] = base[j];
		i = i + 2;
		j++;
	}
	return (ft_convert_base(tab, base, ft_strlen(base) * 2, str) * sign);
}
