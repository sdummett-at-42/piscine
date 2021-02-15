/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 16:00:42 by sdummett          #+#    #+#             */
/*   Updated: 2021/02/15 09:34:56 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int ft_strlen(char *str)
{
	int len;

	len = 0;
	while (str[len] != 0)
		len++;
	return(len);
}

char *ft_strdup(char *src)
{
	char *dest;

	dest = (char *)malloc(sizeof(char) * ft_strlen(src));
	dest = src;
	return (dest);
}
