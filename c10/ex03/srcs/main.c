/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 01:20:44 by sdummett          #+#    #+#             */
/*   Updated: 2021/03/19 19:48:57 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

void	*ft_print_memory(void *addr, unsigned int size);
#include <stdio.h>

void	ft_puterror(char *filename)
{
	ft_putstr("ft_hexdump");
	ft_putstr(filename);
	ft_putstr(": ");
	ft_putstr(strerror(errno));
	ft_putstr("\n");
}

int	compute_bufsize(char *filename)
{
	int	fd;
	int	ret;
	int	buf_size;
	char	buf[30000];

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_puterror(filename);
		return (0);
	}
	ret = read(fd, buf, 30000);
	buf_size = ret;
	while (ret)
	{
		ret = read(fd, buf, 30000);
		buf_size = buf_size + ret;
	}
	close(fd);
	return (buf_size);
}

char	*create_buf(char *filename)
{
	int	fd;
	int	ret;
	int	buf_size;
	char	*buf;

	buf_size = compute_bufsize(filename);
	if (!buf_size)
		return (0);
	buf = malloc(sizeof(char) * buf_size + 1);
	if (!buf)
		return (0);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_puterror(filename);
		return (0);
	}
	ret = read(fd, buf, buf_size);
	buf[ret] = 0;
	close(fd);
	return (buf);
}

int	shift_bytes(char *s1, char *s2, int index)
{
	int	i;
	int	diff;

	i = 0;
	while (*(s1 + index))
	{
		*(s1 + i) = *(s1 + index);
		i++;
		index++;
	}
	diff = i - 16;
	index = 0;
	while (i < 16)
	{
		*(s1 + i) = *(s2 + index);
		i++;
		index++;
	}
	*(s1 + i) = 0;
	return (diff);
}

int	ft_strcmp_16bytes(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (*(s1 + i) && i < 16)
	{
		if (*(s1 + i) != *(s2 + i))
			return (*(s1 + i) - *(s2 + i));
		i++;
	}
	return (*(s1 + i - 1) - *(s2 + i - 1));
}

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
				if (ft_strcmp_16bytes(buf + j, buf + j + 16) == 0)
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
