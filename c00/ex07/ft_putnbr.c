/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 15:50:44 by sdummett          #+#    #+#             */
/*   Updated: 2021/02/03 17:12:42 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>

void ft_putnbr(int nb) {
	char c;

	if (nb < 0) {
		write(1, "-", 1);
		nb = -1 * nb;
		printf("%d", nb);
	}
	if (nb == 0) {
		write(1, "0", 1);
	}
	else {
		while (nb != 0) {
			c = (nb / 10) + '0';
			write(1, &c, 1);
			nb = nb % 10;
		}
	}
}

int main() {
	int nb = -100;
	ft_putnbr(nb);
}
