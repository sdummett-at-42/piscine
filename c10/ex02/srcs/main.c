/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 23:22:11 by sdummett          #+#    #+#             */
/*   Updated: 2021/03/18 22:33:46 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"
#include <stdio.h>

void	ft_putbuf(char *str, int ret)
{
	write(1, str, ret);
}

void	ft_puterror(char *file_name)
{
	ft_putstr("ft_cat: ");
	ft_putstr(file_name);
	ft_putstr(": ");
	ft_putstr(strerror(errno));
	ft_putstr("\n");
}

void	ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (*(src + i))
	{
		*(dest + i) = *(src + i);
		i++;
	}
	*(dest + i) = 0;
}

void	ft_display_file(char *file_name, int buf_size)
{
	int	fd;
	int	ret;
	char	*buf;
	char	*buf2;

	buf = malloc(sizeof(char) * buf_size + 1);
	if (!buf)
		return ;
	buf2 = malloc(sizeof(char) * buf_size + 1);
	if (!buf2)
		return ;
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{	
		ft_puterror(file_name);
		return ;
	}
	ret = read(fd, buf, buf_size);
	if (ret < 0)
	{
		ft_puterror(file_name);
		return ;
	}
	buf[ret] = 0;
	while (ret)
	{	
		ft_strcpy(buf2, buf);
		ret = read(fd, buf, buf_size);
		buf[ret] = 0;
		if (ret < buf_size)
		{
			if (ft_strlen(buf2) && ret != buf_size)
				ft_putbuf(buf2 + ret, ft_strlen(buf2) - ret);
			ft_putbuf(buf, ret);
			break;
		}
	}
	close(fd);
	free(buf);
	free(buf2);
}

int	main(int ac, char *av[])
{
	int	i;
	int	buf_size;

	if (ac < 2)
	{
		printf("Enter '-c' to run the program.\n");
		return (0);
	}
	if (is_minus_c(av[1]) == 2)
	{
		buf_size = compute_bufsize(av[1], 2);
		if (ac == 2 && buf_size != -1)
		{
			//LIRE SUR STDIN
			ft_putstr(">>>>>READ ON STDIN<<<<<\n");
			return (0);
		}
		else if (buf_size != -1)
		{
			//open file(s)
			i = 2;
			if (i + 1 == ac)
			{
				ft_display_file(av[i], buf_size);
				return (0);
			}
			while (i < ac)
			{
				ft_putstr("==> ");
				ft_putstr(av[i]);
				ft_putstr(" <==\n");
				ft_display_file(av[i], buf_size);
				i++;
				if (i != ac)
					ft_putstr("\n");
			}
		}
	}
	else if (is_minus_c(av[1]) == 1 && ac > 2)
	{
		buf_size = compute_bufsize(av[2], 0);
		if (ac == 3 && buf_size != -1)
			ft_putstr(">>>>>READ ON STDIN<<<<<\n");
		else if (buf_size != -1)
		{
			//open file(s)
			i = 3;
			if (i + 1 == ac)
			{
				ft_display_file (av[i], buf_size);
				return (0);
			}
			while (i < ac)
			{
				ft_putstr("==> ");
				ft_putstr(av[i]);
				ft_putstr(" <==\n");
				ft_display_file (av[i], buf_size);
				i++;
				if (i != ac)
					ft_putstr("\n");
			}
		}
	}
	else
	{
		ft_putstr("ft_tail: option requires an argument -- 'c'\n");
		ft_putstr("Try 'ft_tail --help' for more information.\n");
	}
	return (0);
}
