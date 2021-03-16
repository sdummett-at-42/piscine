/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 15:36:26 by sdummett          #+#    #+#             */
/*   Updated: 2021/03/16 19:31:25 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#define BUF_SIZE 29999

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
		ft_putstr("cat: ");
		ft_putstr(file_name);
		ft_putstr(": No such file or directory\n");
		return ;
	}
	ret = read(fd, buf, BUF_SIZE);
	buf[ret] = 0;
	while (ret)
	{
		ft_putstr(buf);
		ret = read(fd, buf, BUF_SIZE);
		buf[ret] = 0;
	}
	close(fd);
}

void	ft_display_stdin(void)
{
	int	ret;
	char	buf[BUF_SIZE + 1];

	while (1)
	{
		ret = read(0, buf, BUF_SIZE);
		buf[ret] = 0;
		while (ret)
		{
			ft_putstr(buf);
			ret = read(0, buf, BUF_SIZE);
			buf[ret] = 0;
		}
	}
}

int	main(int ac, char *av[])
{
	int	i;

	if (ac == 1)
	{
		ft_display_stdin();
		return (0);
	}
	i = 1;
	while (i < ac)
	{
		ft_display_file(av[i]);
		i++;
	}
	return (0);
}
