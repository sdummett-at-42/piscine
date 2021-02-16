/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 12:37:23 by sdummett          #+#    #+#             */
/*   Updated: 2021/02/16 21:24:31 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int len;

	len = 0;
	while (str[len] != 0)
		len++;
	return (len);
}

int	ft_check_charset(char c, char *charset)
{
	int i;

	i = 0;
	while (charset[i] != 0)
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_create_tab(char *str, char *charset, int *tab)
{
	int i;
	int j;
	int size;
	int temp;

	i = 0;
	size = 0;
	//THIS CODE WORK
//	while (charset[i] != 0)
//	{
		//j = 0;
	//	while (str[j] != 0)
	//	{
	//		if (str[j] == charset[i])
	//		{
	//			tab[size] = j;
	//			size++;
	//		}
	//		j++;
	//	}
		//i++;
		//if (charset[i] == 0 && str[j] != 0)
		//	i = 0;
//	}
//------------------------------------------------------------------------//
	char c;
	c = charset[0];
	c++;
	j = 0;
	while (str[j] != 0)
	{
		if (ft_check_charset(str[j], charset))
		{
			while (ft_check_charset(str[j], charset) && str[j] != 0)
			{
				tab[size] = j;
				j++;
				size++;
			}
		}
		else
		{
			j++;
		}
	}
//------------------------------------------------------------------------//
	i = 0;
	while (i < size - 1)
	{
		if (tab[i] > tab[i + 1])
		{
			temp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = temp;
			i = 0;
		}
		else
			i++;
	}
	i = 0;
	while (i < size)
	{
		printf("tab[%d]%d\n", i, tab[i]);
		i++;
	}
	return (size);
}

int	ft_count_strings(char *str, char *charset)
{
	int i;
	int j;
	int len;
	int *tab;

	tab = (int *)malloc(sizeof(int) * ft_strlen(str));
	j = ft_create_tab(str, charset, tab);
	i = 0;
	if (tab[0] == 0)
	{
		i = 0;
		while (tab[i] == tab[i + 1] - 1)
			i++;
		i++;
	}
	while (i < j)
	{
		if (tab[i] == tab[i + 1] - 1 )
			i++;
		else
		{
			len++;
			i++;
		}
		if (i == j && tab[i - 1] + 1 != ft_strlen(str))
			len++;
	}
	return (len);
}

int	**ft_split(char *str, char *charset)
{
	int i;
	int j;
	int len;
	char **strings;

	len = ft_count_strings(str, charset);
	strings = (char **)malloc(sizeof(char *) * len + 1);
	i = 0;
	j = 0;
	while (*str != 0)
	{
		if (ft_check_charset(*str, charset))
			str++;
		else
		{
			i = 0;
			len = 0;
			while (!(ft_check_charset(str[i], charset))
					&& str[i] != 0)
			{
				i++;
				len++;
			}
			strings[j] = (char *)malloc(sizeof(char) * len + 1);
			i = 0;
			while (i < len)
			{
				strings[j][i] = *str;
				str++;
				i++;
			}
			j++;
		}
	}
	strings[j] = 0;
	i = 0;
	while (strings[i] != 0)
	{
		printf("strings[%d]%s\n", i, strings[i]);
		i++;
	}
	return (0);
}

int main()
{
	char charset[] = "-+";
	char str[] = "Hello-Yo-+Salit ca va?+ yep- yes-s-t-u";
	ft_split(str, charset);//"Hello world, coucou", " ,"
}
