/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 20:37:01 by sdummett          #+#    #+#             */
/*   Updated: 2021/02/19 21:17:43 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>
int ft_strcmp(char *s1, char *s2);
void ft_putstr(char *str);


int main()
{
	char chaine1[] = "i";
	char chaine2[] = "qq";

	printf("%d_ft\n", ft_strcmp(chaine1, chaine2));
	printf("%d_cmp\n", strcmp(chaine1, chaine2));
	ft_putstr(chaine1);
	return (0);
}
