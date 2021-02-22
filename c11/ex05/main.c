/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 21:39:25 by sdummett          #+#    #+#             */
/*   Updated: 2021/02/22 22:59:20 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
int	add(int a, int b);
int	sub(int a, int b);
int	mult(int a, int b);
int	div(int a, int b);
int	mod(int a, int b);

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	else if (nb < 0)
	{
		ft_putchar('-');
		nb *= -1;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putchar(nb % 10 + 48);
	}
	else
		ft_putchar(nb + 48);
}

int	ft_atoi(char *str)
{
	int sign;
	int nb;

	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	nb = 0;
	while (*str >= '0' && *str <= '9')
	{
		nb = nb * 10 + *str - 48;
		str++;
	}
	return (nb * sign);
}

int	main(int argc, char *argv[])
{
	int (*op[5])(int, int) = {&add, &sub, &mult, &div, &mod};

	if (argc != 4)
		return (0);
	if (check_op(argv[2][0]))
	{
		ft_putstr("0");
		return (0);
	}
	if (argv[2][0] == '+')
		ft_putnbr(op[0](ft_atoi(argv[1]), ft_atoi(argv[3])));
	else if (argv[2][0] == '-')
		ft_putnbr(op[1](ft_atoi(argv[1]), ft_atoi(argv[3])));
	else if (argv[2][0] == '*')
		ft_putnbr(op[2](ft_atoi(argv[1]), ft_atoi(argv[3])));
	else if (argv[2][0] == '/')
	{
		if (ft_atoi(argv[3]) == 0)
			ft_putstr("Stop : division by zero");
		else
			ft_putnbr(op[3](ft_atoi(argv[1]), ft_atoi(argv[3])));
	}
	else if (argv[2][0] == '%')
	{
		if (ft_atoi(argv[3]) == 0)
			ft_putstr("Stop : modulo by zero");
		else
			ft_putnbr(op[4](ft_atoi(argv[1]), ft_atoi(argv[3])));
	}
	ft_putchar('\n');
	return (0);
}
