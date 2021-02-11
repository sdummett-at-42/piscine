/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 15:14:06 by sdummett          #+#    #+#             */
/*   Updated: 2021/02/11 17:19:58 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return(i);
}

void ft_putstr(char *str, int strlen)
{
	write(1, str, strlen);
	write(1, "\n", strlen);
}

int main(int argc, char *argv[])
{
	int i;
	int j;

	i = 1;
	while (i < argc)
	{
		ft_putstr(argv[i], ft_strlen(argv[i]));
		ft_putstr("\n", 1);
	}
	return (0);
}
