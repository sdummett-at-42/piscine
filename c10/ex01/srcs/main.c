/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 15:36:26 by sdummett          #+#    #+#             */
/*   Updated: 2021/03/17 19:33:57 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

void	ft_puterror(char *file_name)
{
	ft_putstr("ft_cat: ");
	ft_putstr(file_name);
	ft_putstr(": ");
	ft_putstr(strerror(errno));
	ft_putstr("\n");
}

void	ft_display_file(char *file_name)
{
	int	fd;
	int	ret;
	char buf[BUF_SIZE + 1];

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{	
		ft_puterror(file_name);
		return ;
	}
	ret = read(fd, buf, BUF_SIZE);
	if (ret < 0)
	{
		ft_puterror(file_name);
		return ;
	}
	buf[ret] = 0;
	while (ret)
	{
		ft_putbuf(buf, ret);
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
