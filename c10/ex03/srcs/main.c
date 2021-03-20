/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 01:20:44 by sdummett          #+#    #+#             */
/*   Updated: 2021/03/20 18:03:18 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

void	buffer_manager(char **filename, int nboffiles)
{
	int		i;
	int	 	j;
	int		bufsize;
	int		token;
	long int	hex;
	char		*buf;
//	char		*bytesToCmp_temp[33];

	i = 1;
	j = 0;
	hex = 0;
	token = 0;
	buf = create_buf(filename[i]);
	bufsize = compute_bufsize(filename[i]);
	if (i + 1 == nboffiles && bufsize < 32)
	{
		while (bufsize)
		{
			if (bufsize > 16)
			{
				putaddr_inhex(hex);
				ft_print_memory(buf + j, 16);
				j = j + 16;
				hex++;
			}
			else if (bufsize > 0)
			{
				putaddr_inhex(hex);
				ft_print_memory(buf + j, bufsize);
				return ;
			}
			bufsize = bufsize - 16;
		}
	}
	//while (i < nboffiles)
	//{

	//}
	free(buf);
}

int	main(int ac, char *av[])
{
	if (ac == 1)
		return (0);
	buffer_manager(av, ac);
	return (0);
}
