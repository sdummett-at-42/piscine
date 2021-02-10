/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 15:14:48 by sdummett          #+#    #+#             */
/*   Updated: 2021/02/10 17:10:57 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr(char *str, int str_len)
{
	write(1, str, str_len);
	write(1, "\n", 1);
}

void	ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

int	ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] != 0)
	{
		if (s2[i] == 0)
			return (s1[i]);
		if (s1[i] > s2[i] || s2[i] > s1[i]) 
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}
//
//		SEGMENTATION FAULT 
//
void	ft_sort_params(char *param[], int tab_size)
{
	int i;
	char str[100000];

	i = 1;
	while (i < tab_size - 1)
	{
		if (ft_strcmp(param[i], param[i + 1]) > 0)
		{
			ft_strcpy(str, param[i]);
			ft_strcpy(param[i], param[i + 1]);
			ft_strcpy(param[i + 1], str);
			i = 0;
		}
		else
			i++;
	}
}

int	main(int argc, char *argv[])
{
	int i;
	int j;
	int tab[argc];

	if (argc == 1)
		return (0);
	if (argc == 2)
	{
		ft_putstr(argv[1], ft_strlen(argv[1]));
		return (0);
	}
	ft_sort_params(&argv[0], argc);
	i = 1;
	while (i < argc)
	{
		ft_putstr(argv[i], ft_strlen(argv[i]));
		i++;
	}
	return (0);
}
