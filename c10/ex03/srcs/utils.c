/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 19:31:02 by sdummett          #+#    #+#             */
/*   Updated: 2021/03/26 23:18:46 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"
#include <stdio.h>

void	ft_puterror(char *filename)
{
	write(2, "ft_hexdump: ", 12);
	write(2, filename, ft_strlen(filename));
	write(2, ": ", 2);
	write(2, strerror(errno), ft_strlen(strerror(errno)));
	write(2, "\n", 1);
}

int	checkerror(char *filename)
{
	int		fd;
	char	buf[1];

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_puterror(filename);
		return (-1);
	}
	read(fd, buf, 1);
	if (errno)
	{
		ft_puterror(filename);
		return (1);
	}
	close(fd);
	return (0);
}

int	compute_bufsize(char *filename)
{
	int	fd;
	int	ret;
	int	buf_size;
	char	buf[30000];

	fd = open(filename, O_RDONLY);
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

char	*createbuf(char *filename)
{
	int	fd;
	int	ret;
	int	buf_size;
	char	*buf;

	if (checkerror(filename))
		return (0);
	buf_size = compute_bufsize(filename);
	if (!buf_size)
		return (0);
	buf = malloc(sizeof(char) * buf_size + 1);
	if (!buf)
		return (0);
	fd = open(filename, O_RDONLY);
	ret = read(fd, buf, buf_size);
	buf[ret] = 0;
	close(fd);
	return (buf);
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (*(str + len))
		len++;
	return (len);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	int	i;

	if (!(dest == src))
	{
		i = 0;
		while (n--)
		{
			*((unsigned char *)dest + i) = *((unsigned char *)src
					+ i);
			i++;
		}
	}
	return (dest);
}

int	ft_memcmp(const void *b1, const void *b2, size_t len)
{
	while (--len)
	{
		if (*(unsigned char *)b1 != *(unsigned char *)b2)
			return (*(unsigned char *)b1 - *(unsigned char *)b2);
		b1++;
		b2++;
	}
	return (*(unsigned char *)b1 - *(unsigned char *)b2);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

void	ft_putbuf(char *str, int ret)
{
	write(1, str, ret);
}
