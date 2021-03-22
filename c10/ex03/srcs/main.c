/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 01:20:44 by sdummett          #+#    #+#             */
/*   Updated: 2021/03/22 12:08:12 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

void	shiftbytes(void *addr)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		*(unsigned char *)(addr + i) = *(unsigned char *)(addr + i + 16);
		i++;
	}
}

void	buffer_manager(char **filename, int nfiles)
{
	//which variables needs to be unsigned long ?
	char	tmp[32];
	char	*buf;
	int	currfile;
	unsigned long	nbytes;
	int	diff;
	int	i;
	unsigned long	j;
	unsigned long	hex;

	i = 0;
	j = 0;
	currfile = 1;
	buf = createbuf(filename[currfile]);
	nbytes = compute_bufsize(filename[currfile]);
	while (i < 16)
	{
		while (i < 16 && j < nbytes)
		{
			tmp[i] = buf[j];
			i++;
			j++;
		}
		if (i < 16)
		{
			if (currfile + 1 < nfiles)
			{
				free(buf);
				currfile++;
				buf = createbuf(filename[currfile]);
				nbytes = compute_bufsize(filename[currfile]);
				j = 0;
			}
			else
			{
				puthex(0, 1);
				ft_print_memory(tmp, i);
				return ;
			}
		}
	}
	hex = 0;
	diff = 0;
	while (currfile < nfiles)
	{
		i = 0;
		while (i < 16)
		{
			while (i < 16 && j < nbytes)
			{
				tmp[16 + i] = buf[j];
				i++;
				j++;
				hex++;
			}
			if (i < 16)
			{
				if (currfile + 1 < nfiles)
				{
					free(buf);
					currfile++;
					buf = createbuf(filename[currfile]);
					nbytes = compute_bufsize(filename[currfile]);
					j = 0;
				}
				else
				{
					if (diff == 0)
					{
						puthex(hex - i, 1);
						ft_print_memory(tmp, 16);
						hex = hex + 16;
					}
					if (i)
					{

						puthex(hex - i, 1);
						ft_print_memory(tmp + 16, i);
						puthex(hex, 0);
					}
					else
						puthex(hex, 0);
					
					free(buf);
					return ;
				}
			}
		}
		if (ft_memcmp(tmp, tmp + 16, 16))
		{
			if (diff == 0)
			{
				puthex(hex - 16, 1);
				ft_print_memory(tmp, 16);
			}
			diff = 0;
		}
		else if (diff == 0)
		{
			puthex(hex - 16, 1);
			ft_print_memory(tmp, 16);
			ft_putstr("*\n");
			diff = 1;
		}
		shiftbytes(tmp);
	}
}

int	main(int ac, char *av[])
{
	if (ac == 1)
		return (0);
	buffer_manager(av, ac);
	return (0);
}
