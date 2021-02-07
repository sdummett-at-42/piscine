/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 13:46:24 by sdummett          #+#    #+#             */
/*   Updated: 2021/02/07 14:06:02 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	int i;
	unsigned int j;

	i = 0;
	while (dest[i] != '\0')
		i++;
	j = 0;
	while (j < nb && *src != '\0')
	{
		dest[i] = *src;
		src++;
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}
int main()
{
	char source[] = "123";
	char desti[100] = "     ";

	//printf("return>%s< dest>%s< source>%s<", strncat(desti, source, 5), desti, source);
	printf("return>%s< dest>%s< source>%s<", ft_strncat(desti, source, 5), desti, source);
}
