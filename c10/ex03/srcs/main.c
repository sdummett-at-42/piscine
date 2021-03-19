/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 01:20:44 by sdummett          #+#    #+#             */
/*   Updated: 2021/03/19 15:35:03 by sdummett         ###   ########.fr       */
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

int	ft_strcmp_8bytes(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (*(s1 + i) && i < 8)
	{
		if (*(s1 + i) != *(s2 + i))
			return (*(s1 + i) - *(s2 + i));
		i++;
	}
	return (*(s1 + i) - *(s2 + i));
}

void	buffer_manager(char **filename, int size)
{
	//free(buf)
	int		i;
	int	 	j;
	int		buf_size;
	int		token;
	//unsigned int	hex;
	char		*buf;
	char		*buf_temp;

	i = 1;
	j = 0;
	token = 1;
	buf = create_buf(filename[i]);
	buf_size = compute_bufsize(filename[i]);
//	ft_putaddr_inhex(j);
//	ft_print_memory()
	while (i < size)
	{
		while (j < buf_size)
		{
			if (j + 16 < buf_size)
			{
				if (ft_strcmp_8bytes(buf + j, buf + j + 8) == 0)
				{
					if (j == 0 && i == 1)
						ft_print_memory(buf, 8);
					if (token)
					{
						ft_putstr("*\n");
						token = 0;
					}
				}
				else
					token = 1;
			}
			else
			{
				if (i + 1 == size)
					ft_print_memory(buf + j, buf_size - j);
				else
				{
					if (compute_bufsize(filename[i + 1]) > j + 16 - buf_size)
						ft_print_memory(buf + j, buf_size - j);
					else
					{
						buf_temp = create_buf(filename[i + 1]);
						shift_bytes(buf, buf_temp, j);
						if (ft_strcmp_8bytes(buf, buf + 8) == 0)
						{
							ft_putstr("*");
						}
						else
						{
							token = 1;
							ft_print_memory(buf, 8);
						}
						
					}
				}
				//keep a token to know if we need to print the next "*".
			}
			j = j + 8;
		}
		//ft_print_memory(buf, compute_bufsize(filename[i]));
		i++;
	}
}

int	main(int ac, char *av[])
{
	//int	i;

	if (ac == 1)
		return (0);
	buffer_manager(av, ac);
//	i = 1;
//	while (i < ac)
//	{
//		ft_print_memory(create_buf(av[i]), compute_bufsize(av[i]));
//		i++;
//	}
	return (0);
}
