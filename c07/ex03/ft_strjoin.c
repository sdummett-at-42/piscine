/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 16:02:19 by sdummett          #+#    #+#             */
/*   Updated: 2021/02/17 12:30:59 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int len;

	len = 0;
	while (str[len] != 0)
		len++;
	return (len);
}

char	*ft_strcat(char *dest, char *src)
{
	int i;
	int j;

	i = 0;
	while (dest[i] != 0)
		i++;
	j = 0;
	while (src[j] != 0)
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = 0;
	return (dest);
}

char	*ft_strjoin_bis(int size, char **strs, char *sep)
{
	int		i;
	int		len;
	char	*dest;

	i = 0;
	len = ft_strlen(sep);
	while (i < size)
	{
		len = len + ft_strlen(strs[i]);
		i++;
	}
	if (!(dest = (char *)malloc(sizeof(dest) * len + 1)))
		return (0);
	dest[0] = 0;
	i = 0;
	while (i < size)
	{
		ft_strcat(dest, strs[i]);
		if (i + 1 != size && i + 2 != size)
			ft_strcat(dest, sep);
		i++;
	}
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char *dest;

	if (size == 0)
	{
		if (!(dest = (char *)malloc(sizeof(dest) * 1)))
			return (0);
		dest[0] = 0;
		return (dest);
	}
	return (ft_strjoin_bis(size, strs, sep));
}
