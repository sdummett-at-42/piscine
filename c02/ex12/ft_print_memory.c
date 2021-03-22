/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 11:04:08 by sdummett          #+#    #+#             */
/*   Updated: 2021/03/22 18:21:00 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	putaddr_inhex(long int addr)
{
	int	i;
	char	str[17];
	char	*hexbase;

	hexbase = "0123456789abcdef";
	i = 0;
	while (i < 16)
	{
		str[i] = '0';
		i++;
	}
	str[i] = 0;
	while (addr)
	{
		str[i - 1] = *(hexbase + addr % 16);
		addr = addr / 16;
		i--;
	}
	write(1, str, 16);
	write(1, ": ", 2);
}

void	ft_puthex(int ch)
{
	char	*hex_base;

	hex_base = "0123456789abcdef";
	if (ch > 15)
	{
		ft_puthex(ch / 16);
		write(1, (hex_base + (ch % 16)), 1);
	}
	else
		write(1, (hex_base + (ch % 16)), 1);
}

void	ft_putspace(int j)
{
	if ((j == 15 || j % 2 == 1) && j != 16)
	{
		write(1, "   ", 3);
		j++;
	}
	while (j < 16)
	{
		if (j == 1)
			write(1, "  ", 2);
		if (j % 2)
			write(1, " ", 1);
		else
			write(1, "    ", 4);
		j++;
	}
}

void	ft_putstr_dot_nonprintable(char *str, int j, int size)
{
	int	i;

	ft_putspace(j);
	i = 0;
	while (i < 16 && i < size)
	{
		if (*(str + i) >= 32 && *(str + i) <= 126)
			write(1, str + i, 1);
		else
			write(1, ".", 1);
		i++;
	}
	write(1, "\n", 1);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	int	ch;
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < size)
	{
		if ((i + 1) % 16 == 1)
			putaddr_inhex((long int)(addr + i));
		ch = *(unsigned char *)(addr + i);
		if (ch < 16)
			write(1, "0", 1);
		ft_puthex(ch);
		if ((i + 1) % 2 == 0)
			write(1, " ", 1);
		i++;
		j++;
		if ((i + 1) % 16 == 1 || i == size)
		{
			ft_putstr_dot_nonprintable((char *)(addr + i - j), j, size - i +j);
			j = 0;
		}
	}
	return (addr);
}
