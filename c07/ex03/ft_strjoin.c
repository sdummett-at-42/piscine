/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 16:02:19 by sdummett          #+#    #+#             */
/*   Updated: 2021/02/15 16:58:39 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
//Ecrire une fonction qui va concatener l’ensemble des chaîne de caractères pointées par strs en les séparants à l’aide de sep.
//•size représente la taille de strs.
//•Si size vaut 0, il faut retourner une chaîne de caractères vide que l’on peut free()
#include <stdio.h>
#include <stdlib.h>

int ft_strlen(char *str)
{
	int len;

	len = 0;
	while (str[len] != 0)
		len++;
	return (len);
}

char *ft_strcat(char *dest, char *src)
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

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char *dest;
	int i;
	int len;

	if (size == 0)
	{
		dest = (char *)malloc(sizeof(dest) * 1);
		dest[0] = 0;
		return (dest);
	}
	//printf("strs[3]>%s<, sep:>%s<, size:%d\n", strs[3], sep, size);
	i = 0;
	len = ft_strlen(sep);
	while (i < size)
	{
		len = len + ft_strlen(strs[i]);
		i++;
	}
	dest = (char *)malloc(sizeof(dest) * len + 1);
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

int main()
{
	char *chaine[4];
	char sep[] = "*";
	chaine[0] = "Bonjour";
	chaine[1] = "Hello";
	chaine[2] = "Chill";
	chaine[3] = "Guyane";

	int size = 5;

	printf("ft_strjoin:>%s<",ft_strjoin(size, chaine, sep));
}
