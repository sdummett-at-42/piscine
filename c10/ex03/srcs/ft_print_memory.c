/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 01:35:10 by sdummett          #+#    #+#             */
/*   Updated: 2021/03/20 18:06:25 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"
#include <stdio.h>

void	putaddr_inhex(long int addr)
{
	int	i;
	char	str[9];
	char	*hexbase;

	hexbase = "0123456789abcdef";
	i = 0;
	while (i < 8)
	{
		str[i] = '0';
		i++;
	}
	str[i] = 0;
	while (addr)
	{
		str[i - 2] = *(hexbase + addr % 16);
		addr = addr / 16;
		i--;
	}
	ft_putstr(str);
	ft_putstr("  ");
}

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

void	ft_putspace(int j)
{
	while (j < 16)
	{
		ft_putstr("   ");
		j++;
		if (j == 8 || j == 16)
			ft_putstr(" ");

	}
}

void	ft_putstr_dot_nonprintable(char *str, int j)
{
	int	i;

	ft_putspace(j);
	ft_putstr("|");
	i = 0;
	while (*(str + i) && i < 16)
	{
		if (*(str + i) >= 32 && *(str + i) <= 126)
			write(1, str + i, 1);
		else
			write(1, ".", 1);
		i++;
	}
	ft_putstr("|");
	write(1, "\n", 1);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	int	ch;
	unsigned int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < size)
	{
		//if ((i + 1) % 16 == 1)
		//	putaddr_inhex(i);
		ch = *(char *)(addr + i);
		if (ch < 17)
			write(1, "0", 1);
		ft_puthex(ch);
		if (j + 1 == 8 || j + 1 == 16)
			ft_putstr(" ");
		ft_putstr(" ");
		i++;
		j++;
		if ((i + 1) % 16 == 1 || i == size)
		{
			ft_putstr_dot_nonprintable((char *)(addr + i - j), j);
			j = 0;
		}
	}
	return (addr);
}
