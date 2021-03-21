/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 01:20:44 by sdummett          #+#    #+#             */
/*   Updated: 2021/03/21 01:29:50 by sdummett         ###   ########.fr       */
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
	int	i;
	int	j;

	//nfiles = 1000;
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
/*	while (currfile < nfiles)
	{
		buf = createbuf(filename[currfile]);

		currfile++;
	}
*/
}

int	main(int ac, char *av[])
{
	if (ac == 1)
		return (0);
	buffer_manager(av, ac);
	return (0);
}
