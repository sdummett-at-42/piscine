/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_with_non_printable.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 09:57:18 by sdummett          #+#    #+#             */
/*   Updated: 2021/03/14 11:03:10 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_puthex(int ch)
{
	char	*hex_base;
	
	hex_base = "0123456789abcdef";
	if (ch > 0)
	{
		ft_puthex(ch / 16);
		write(1, (hex_base + (ch % 16)), 1);
	}
}

void	ft_putstr_with_non_printable(char *str)
{
	int	conv;

	while (*str)
	{
		if (*str >= 32 && *str <= 126)
			write(1, str, 1);
		else
		{
			conv = *str;
			write(1, "\\", 1);
			if (*str < 16)
				write(1, "0", 1);
			ft_puthex(*str);
		}
		str++;
	}
}
