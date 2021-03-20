/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 19:31:02 by sdummett          #+#    #+#             */
/*   Updated: 2021/03/20 16:43:42 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (*(str + len))
		len++;
	return (len);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	int	i;

	if (!(dest == src))
	{
		i = 0;
		while (n--)
		{
			*((unsigned char *)dest + i) = *((unsigned char *)src
					+ i);
			i++;
		}
	}
	return (dest);
}

int	ft_memcmp(const void *b1, const void *b2, size_t len)
{
	while (--len)
	{
		if (*(unsigned char *)b1 != *(unsigned char *)b2)
			return (*(unsigned char *)b1 - *(unsigned char *)b2);
		b1++;
		b2++;
	}
	return (*(unsigned char *)b1 - *(unsigned char *)b2);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

void	ft_putbuf(char *str, int ret)
{
	write(1, str, ret);
}
