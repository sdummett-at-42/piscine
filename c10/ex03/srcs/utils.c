/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 19:31:02 by sdummett          #+#    #+#             */
/*   Updated: 2021/03/21 00:27:25 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

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

char	*createbuf(char *filename)
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
