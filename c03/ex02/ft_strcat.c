/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 13:18:13 by sdummett          #+#    #+#             */
/*   Updated: 2021/02/07 13:40:01 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
char	*ft_strcat(char* dest, char* src)
{
	int i;

	i = 0;
	while (dest[i] != '\0')
		i++;
	while (*src != '\0')
	{
		dest[i] = *src;
		src++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
			
}
int main()
{
	char source[] = "1111111";
	char dest[100] = "";
	//printf("return>%s< dest>%s< source>%s<", strcat(dest, source), dest, source);
	printf("return>%s< dest>%s< source>%s<", ft_strcat(dest, source), dest, source);
}
