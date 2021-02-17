/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 19:40:46 by sdummett          #+#    #+#             */
/*   Updated: 2021/02/17 11:37:04 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str);
int		ft_base_is_manipulable(char c, char *base);
void	ft_strcpy(char *dest, char *src);
void	ft_strrev(char *str);

int		ft_nbr_is_convertissable(char *nbr, char *base)
{
	int j;
	int len;
	int match;

	len = 0;
	while (nbr[len] != 0)
	{
		j = 0;
		match = 0;
		while (base[j] != 0)
		{
			if (base[j] == nbr[len])
				match++;
			j++;
		}
		if (match == 0)
			return (len);
		len++;
	}
	return (len);
}

int		ft_check_base(char *base)
{
	int			i;
	int			j;
	char		c;

	if (*base == 0 || ft_strlen(base) == 1)
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

int		ft_convert_to_base10(char *nbr, char *base_from, int len)
{
	int i;
	int nb;
	int base_size;

	base_size = ft_strlen(base_from);
	nb = nbr[0] - 48;
	i = 1;
	while (i < len)
	{
		nb = nb * base_size + ft_base_is_manipulable(nbr[i], base_from);
		i++;
	}
	return (nb);
}

char	*ft_convert_from_base10(int nb, char *base_to, int sign)
{
	int		i;
	int		base_size;
	char	*nbr;
	char	*nbr_temp;

	nbr_temp = (char *)malloc(sizeof(nbr_temp) * 10000);
	base_size = ft_strlen(base_to);
	i = 0;
	while (nb > 0)
	{
		nbr_temp[i] = base_to[nb % base_size];
		nb = nb / base_size;
		i++;
	}
	if (sign < 0)
	{
		nbr_temp[i] = '-';
		i++;
	}
	nbr_temp[i] = '\0';
	ft_strrev(nbr_temp);
	nbr = (char *)malloc(sizeof(nbr) * ft_strlen(nbr_temp) + 1);
	ft_strcpy(nbr, nbr_temp);
	free(nbr);
	return (nbr);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int base10;
	int sign;
	int len;

	sign = 1;
	base10 = 0;
	if (ft_check_base(base_from) || ft_check_base(base_to))
		return (0);
	while ((*nbr >= 9 && *nbr <= 13) || (*nbr == ' '))
		nbr++;
	while (*nbr == '-' || *nbr == '+')
	{
		if (*nbr == '-')
			sign = sign * -1;
		nbr++;
	}
	if (ft_nbr_is_convertissable(nbr, base_from))
	{
		len = ft_nbr_is_convertissable(nbr, base_from);
		base10 = ft_convert_to_base10(nbr, base_from, len);
		return (ft_convert_from_base10(base10, base_to, sign));
	}
	return (0);
}
