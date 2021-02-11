/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 12:09:50 by sdummett          #+#    #+#             */
/*   Updated: 2021/02/11 12:36:59 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str, int str_len)
{
	write(1, str, str_len);
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

int		ft_strlen(char *str)
{
	int			i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_print_base(int *tab, int tab_size, char *base)
{
	int			i;
	char		str[tab_size];

	i = 0;
	while (tab_size > 0)
	{
		str[i] = base[tab[tab_size - 1]];
		tab_size--;
		i++;
	}
	str[i] = '\0';
	ft_putstr(str, ft_strlen(str));
}

void	ft_putnbr_base(int nbr, char *base)
{
	int			i;
	int			tab[20];
	long long	nb;

	nb = nbr;
	if (ft_base_is_ok(base) == 1 || ft_strlen(base) == 1)
		return ;
	if (nb < 0)
	{
		nb *= -1;
		write(1, "-", 1);
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
	ft_print_base(tab, i, base);
}
