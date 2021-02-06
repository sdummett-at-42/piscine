/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 16:10:11 by sdummett          #+#    #+#             */
/*   Updated: 2021/02/06 17:17:56 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int ft_strncmp(char *s1, char *s2, unsigned int n)
{
	int i;

	i = 0;
	while (s1[i] != '\0' && i <= n)
	{
		if (s2[i] == '\0')
			return (1);
		if (s2[i] > s1[i])
			return (-1);
		if (s1[i] > s2[i])
			return (1);
		i++;
	}
	if (s1[i] == s2[i])
		return (0;)
	if (s2[i] >)
		return (-1);
	return (0);
}

int main()
{
	char chaine1[] = "efgh";
	char chaine2[] = "efghjfnkfn";

	printf("strncmp:%d\n", strncmp(chaine1, chaine2, 4));
	printf("ft_strncmp:%d\n", ft_strncmp(chaine1, chaine2, 4));
}
