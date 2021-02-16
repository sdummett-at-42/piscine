/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 19:40:46 by sdummett          #+#    #+#             */
/*   Updated: 2021/02/16 12:36:46 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

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
	dest[i] = '\0';
}

void		ft_strrev(char *str)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	j = ft_strlen(str);
	while (i < j - 1)
	{
		c = str[i];
		str[i] = str[j - 1];
		str[j - 1] = c;
		i++;
		j--;
	}
}

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

int		ft_base_is_manipulable(char c, char *base)
{
	int i;

	i = 0;
	while (base[i] != 0)
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (i);
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

char		*ft_convert_from_base10(int nb, char *base_to)
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
	nbr_temp[i] = '\0';
	ft_strrev(nbr_temp);
	nbr = (char *)malloc(sizeof(nbr) * ft_strlen(nbr_temp) + 1);
	ft_strcpy(nbr, nbr_temp);
	free(nbr);
	return (nbr);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int n;
	//printf("base_from:%d, base_to:%d\n", ft_check_base(base_from), ft_check_base(base_to));	
	if (ft_check_base(base_from) || ft_check_base(base_to))
	{
		printf("ONE OF THE BASE ISNT OKAY!\n");
		return (0);
	}
	if (ft_nbr_is_convertissable(nbr, base_from))
	{
		printf("NBR IS CONVERTISSABLE!\n");
		printf("convertissable_len:%d\n", ft_nbr_is_convertissable(nbr, base_from));
		printf("%s nbr in base 10 = %d\n", nbr, ft_convert_to_base10(nbr, base_from, ft_nbr_is_convertissable(nbr, base_from)));
		n =  ft_convert_to_base10(nbr, base_from, ft_nbr_is_convertissable(nbr, base_from));
		printf("returnfrombase10:>%s<\n", ft_convert_from_base10(1000, base_to));
		
	}	
	return ();
	
}

int	main()
{
	char base_from[] = "01";
	char base_to[] = "0123456789abcdef";
	char nbr[] = "1111011";

	printf(">%s<\n", ft_convert_base(nbr, base_from, base_to));
	return (0);
}
