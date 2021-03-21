/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 01:20:44 by sdummett          #+#    #+#             */
/*   Updated: 2021/03/21 02:28:37 by sdummett         ###   ########.fr       */
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
	char	tmp[32];
	char	*buf;
	int	currfile;
	int	nbytes;
	int	diff;
	int	i;
	int	j;

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
				puthex(0);
				ft_print_memory(tmp, i);
				return ;
			}
		}
	}
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
						puthex(0);
						ft_print_memory(tmp, 16);
					}
					puthex(0);
					ft_print_memory(tmp + 16, i);
					return ;
				}
			}
		}
		if (ft_memcmp(tmp, tmp + 16, 16))
		{
			if (diff == 0)
			{
				puthex(0);
				ft_print_memory(tmp, 16);
			}
			diff = 0;
		}
		else if (diff == 0)
		{
			puthex(0);
			ft_print_memory(tmp, 16);
			ft_putstr("*\n");
			diff = 1;
		}
		shiftbytes(tmp);
		//currfile++;
	}

}

int	main(int ac, char *av[])
{
	if (ac == 1)
		return (0);
	buffer_manager(av, ac);
	return (0);
}
