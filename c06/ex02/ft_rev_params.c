/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 15:14:17 by sdummett          #+#    #+#             */
/*   Updated: 2021/02/10 15:14:25 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main(int argc, char *argv[])
{
	int i;
	int j;
	
	i = 1;
	while (i < argc)
	{
		j = ft_strlen(argv[i]);
		while (j >= 0)
		{
			ft_putchar(argv[i][j]);
			j--;
		}
		ft_putchar('\n');
		i++;
	}
	return (0);
}
