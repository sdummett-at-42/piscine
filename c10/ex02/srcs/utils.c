/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 19:36:23 by sdummett          #+#    #+#             */
/*   Updated: 2021/03/18 19:43:10 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

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

int	is_minus_c(char *arg)
{
	//char	*minus_c;
	//char	*minus_bytes;

	//minus_c = "-c";
	//minus_bytes = "--bytes";
	if (arg[0] != '-')
	       return (0);
	if (arg[1] != 'c')
		return (0);
	if (arg[2] == '\0')
		return (1);
	return (2);
}

int	compute_bufsize(char *arg, int i)
{
	int	j;
	int	buf_size;

	j = i;
	buf_size = 0;
	while (*(arg + i))
	{
		if (!(arg[i] >= '0' && arg[i] <= '9'))
		{
			ft_putstr("tail: invalid number of bytes: '");
			ft_putstr(arg + j);
			ft_putstr("'\n");
			return (-1);
		}
		buf_size = buf_size * 10 + arg[i] - 48;
		i++;
	}
	return (buf_size);
}
