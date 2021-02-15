/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 19:40:46 by sdummett          #+#    #+#             */
/*   Updated: 2021/02/15 20:46:24 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_strlen(char *str)
{
	int len;

	len = 0;
	while (str[len] != 0)
		len++;
	return (len);
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

int		ft_str_is_convertissable(char *nbr, char *base)
{
	int i;
	int j;
	int match;

	i = 0;
	while (nbr[i] != 0)
	{
		j = 0;
		match = 0;
		while (nbr[j] != 0)
		{
			if (base[j] == nbr[i])
				match++;
			j++;
		}
		if (match == 0)
			return (i);
		i++;
	}
	return (i);
}

char		*ft_convert_from_ten(char *nbr, char *base)
{
	
}

char		*ft_convert_to_base_ten(char *nbr, char *base)
{
	
}

int		ft_base_is_ok(char *base)
{
	int			i;
	int			j;
	char		c;

	if (*base == 0)
		return (1);
	i = 0;
	while (base[i])
	{
		if (base[i] == '-' || base[i] == '+')
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

char		*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	if (ft_base_is_ok(base_from) && ft_base_is_ok(base_to))
		return (0);
	
}

int	main()
{
	
}
