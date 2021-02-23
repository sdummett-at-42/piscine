/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 10:01:40 by sdummett          #+#    #+#             */
/*   Updated: 2021/02/23 11:23:27 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//• Écrire la fonction ft_sort_string_tab qui trie par ordre ascii les chaîne de caractères.
//• tab sera terminé par un pointeur nul
//• Le tri s’effectuera en échangeant les pointeurs du tableau.

#include <stdio.h>

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] != '\0')
	{
		if (s2[i] == '\0')
			return (s1[i]);
		if (s2[i] > s1[i])
			return (s1[i] - s2[i]);
		if (s1[i] > s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

void ft_sort_string_tab(char **tab)
{
	char *temp;
	int i;

	temp = tab[1];
	i = 0;
	while (tab[i + 1] != 0)
	{
		if (ft_strcmp(tab[i], tab[i + 1]))
		i++;
	}
}



int main()
{
	char *strs[5];
	strs[0] = "Guyane";
	strs[1] = "Cayenne";
	strs[2] = "St Laurent";
	strs[3] = "Matoury";
	strs[4] = 0;

	ft_sort_string_tab(strs);
}
