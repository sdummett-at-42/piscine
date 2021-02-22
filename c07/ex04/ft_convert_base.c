/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 18:14:23 by sdummett          #+#    #+#             */
/*   Updated: 2021/02/22 08:12:33 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_base_is_ok(char *base);
int			ft_strlen(char *str);
char		*ft_put_base(int *tab, int tab_size, int sign, char *base);

char		*ft_putnbr_base(long long nb, char *base)
{
	int			i;
	int			sign;
	int			tab[50];

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

int			ft_str_is_convertissable(char *str, char *base)
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
	int			i;
	int			j;
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

long long	ft_atoi_base(char *str, char *base, int sign)
{
	int i;
	int j;
	int tab[ft_strlen(base) * 2];

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

char		*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int sign;

	if (ft_strlen(base_from) == 1 || ft_strlen(base_to) == 1)
		return (0);
	if (ft_base_is_ok(base_from) == 1 || ft_base_is_ok(base_to) == 1)
		return (0);
	sign = 1;
	while (*nbr == ' ' || (*nbr >= 9 && *nbr <= 13))
		nbr++;
	while (*nbr == '+' || *nbr == '-')
		if (*nbr++ == '-')
			sign *= -1;
	if (ft_str_is_convertissable(nbr, base_from) == 0)
		return (0);
	return (ft_putnbr_base(ft_atoi_base(nbr, base_from, sign), base_to));
}
