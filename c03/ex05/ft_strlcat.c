/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 15:31:18 by sdummett          #+#    #+#             */
/*   Updated: 2021/02/07 17:16:51 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <bsd/string.h>

unsigned int		ft_strlen(char *str)
{
	unsigned int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return(i);
}
unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int i;

	if (size <= ft_strlen(dest))
		return (size);
	i = 0;
	while (dest[i] != '\0')
		i++;
	while (*src != '\0' && i < size - 1)
	{
		dest[i] = *src;
		src++;
		i++;
	}
	dest[i] = '\0';
	if (ft_strlen(dest) > ft_strlen(src))
		return (ft_strlen(dest) - ft_strlen(src));
	else
		return (ft_strlen(dest) - ft_strlen(src));
}
int main()
{
	char dest[] = "";
	char src[] = "";

	int n = 0;
	strlcat(dest, src, 0);
	//int n = ft_strcat(dest, src, 0);
	printf("return:>%d< src:>%s< dest>%s<\n", n, src, dest);
}
//si src[0] == '\0' return 0;
//return the size of src + ;
