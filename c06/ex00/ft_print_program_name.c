/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 15:13:47 by sdummett          #+#    #+#             */
/*   Updated: 2021/02/11 16:46:47 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_putstr(char *str, int strlen)
{
	write(1, str, strlen);
}

int		main(int argc, char *argv[])
{
	int i;
	
	ft_putstr(argv[argc - 1], ft_strlen(argv[argc - 1]));
	return (0);
}
