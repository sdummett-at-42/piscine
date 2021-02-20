/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 18:14:23 by sdummett          #+#    #+#             */
/*   Updated: 2021/02/20 19:58:25 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_base_is_ok(char *base);
int	ft_strlen(char *str);
char	*ft_put_base(int *tab, int tab_size, int sign, char *base);

char	*ft_putnbr_base(long long nb, char *base)
{
	int			i;
	int			sign;
	int			tab[50];

	if (ft_base_is_ok(base) == 1 || ft_strlen(base) == 1)
		return (0);
	sign = 0;
	if (nb < 0)
	{
		nb *= -1;
		sign = 1;
	}
	i = 0;
	if (nb == 0)
	{
		tab[i] = nb;
		i = 1;
	}
	while (nb > 0)
	{
		tab[i] = nb % ft_strlen(base);
		i++;
		nb = nb / ft_strlen(base);
	}
	return (ft_put_base(tab, i, sign, base));
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

long long	ft_converter(int *tab, char *base, int base_len, char *str)
{
	int		i;
	int		j;
	long long	nb;

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

long long		ft_atoi_base(char *str, char *base)
{
	int i;
	int j;
	int sign;
	int tab[ft_strlen(base) * 2];

	if (ft_base_is_ok(base) == 1)
		return (0);
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	while (*str == '+' || *str == '-')
		if (*str++ == '-')
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
	return (ft_converter(tab, base, ft_strlen(base) * 2, str) * sign);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	return (ft_putnbr_base(ft_atoi_base(nbr, base_from), base_to));
}
