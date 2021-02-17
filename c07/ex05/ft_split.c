/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 12:37:23 by sdummett          #+#    #+#             */
/*   Updated: 2021/02/17 15:51:31 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_check_charset(char c, char *charset)
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

int		ft_count_words(char *str, char *charset)
{
	int i;
	int len;

	i = 0;
	len = 0;
	if (!(ft_check_charset(*str, charset)))
		len++;
	while (*str)
	{
		if (ft_check_charset(*str, charset))
		{
			while (ft_check_charset(*str, charset) && *str != 0)
				str++;
			len++;
		}
		else
			str++;
	}
	if (ft_check_charset(*(str - 1), charset))
		len--;
	return (len);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		j;
	int		len;
	char	**strs;

	strs = (char **)malloc(sizeof(char *) * ft_count_words(str, charset) + 1);
	j = 0;
	while (*str != 0)
	{
		if (ft_check_charset(*str, charset))
			str++;
		else
		{
			len = 0;
			while (!(ft_check_charset(str[len], charset)) && str[len] != 0)
				len++;
			strs[j] = (char *)malloc(sizeof(char) * len + 1);
			i = 0;
			while (i < len)
				strs[j][i++] = *(str++);
			strs[j++][i] = 0;
		}
	}
	strs[j] = 0;
	return (strs);
}
