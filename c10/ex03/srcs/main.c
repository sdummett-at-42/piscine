/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 01:20:44 by sdummett          #+#    #+#             */
/*   Updated: 2021/03/20 16:49:36 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

void	buffer_manager(char **filename, int size)
{
	int		i;
	int	 	j;
	int		buf_size;
	int		token;
	long int	hex;
	char		*buf;
//	char		*buf_temp;

	i = 1;
	j = 0;
	hex = 0;
	token = 0;
	buf = create_buf(filename[i]);
	buf_size = compute_bufsize(filename[i]);
	putaddr_inhex(hex);
	ft_print_memory(buf, 16);
	while (i < size)
	{
		while (j < buf_size)
		{
			if (j + 32 <= buf_size)
			{
				if (ft_memcmp(buf + j, buf + j + 16, 16) == 0)
				{
					if (token || (i == 1 && j == 0))
					{
						if (!(i == 1 && j == 0) || token)
						{
							putaddr_inhex(hex);
							ft_print_memory(buf + j, 16);
						}
						ft_putstr("*\n");
						token = 0;
					}
				}
				else if (token == 1)
				{
					putaddr_inhex(hex);
					ft_print_memory(buf + j, 16);
				}
				else
				{
					token = 1;
				}
			}
			else
			{
				if (i + 1 == size)
				{
					if (token == 1)
					{
						putaddr_inhex(hex);
						ft_print_memory(buf + j, 16);
						putaddr_inhex(hex + 1);
						ft_print_memory(buf + j + 16, buf_size - j - 16);
					}
					else
					{
						putaddr_inhex(hex + 1);
						ft_print_memory(buf + j + 16, buf_size - j - 16);
					}
					j = j + 16;
				}
			}
			j = j + 16;
			hex++;
		}
		i++;
	}
	free(buf);
}

int	main(int ac, char *av[])
{
	if (ac == 1)
		return (0);
	buffer_manager(av, ac);
	return (0);
}
