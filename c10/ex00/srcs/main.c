/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 12:39:11 by sdummett          #+#    #+#             */
/*   Updated: 2021/03/16 15:15:19 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#define BUF_SIZE 15000

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (*(str + len))
		len++;
	return (len);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}


void	ft_display_file(char *file_name)
{	
	int	fd;
	int	ret;
	char buf[BUF_SIZE + 1];

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("Cannot read file.\n");
		return ;
	}
	ret = read(fd, buf, 10);
	buf[ret] = 0;
	while (ret)
	{
		ft_putstr(buf);
		ret = read(fd, buf, 10);
		buf[ret] = 0;
	}
	close(fd);
}

int	main(int ac, char *av[])
{
	if (ac < 2)
	{
		ft_putstr("File name is missing.\n");
		return (0);
	}
	if (ac > 2)
	{
		ft_putstr("Too many arguments.\n");
		return (0);
	}
	ft_display_file(av[1]);
	return (0);
}
