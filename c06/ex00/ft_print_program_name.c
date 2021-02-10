/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 15:13:47 by sdummett          #+#    #+#             */
/*   Updated: 2021/02/10 15:13:50 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main(int argc, char *argv[])
{
	int i;
	
	//printf("argc:%d, argv[%d]:%c\n", argc, argc - 1, argv[argc - 1][0]);
	i = 0;
	while (argv[argc - 1][i] != '\0')
	{
		ft_putchar(argv[argc - 1][i]);
		i++;
	}
	ft_putchar('\n');
	return (0);
}
