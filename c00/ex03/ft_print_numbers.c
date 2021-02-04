/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 08:20:39 by sdummett          #+#    #+#             */
/*   Updated: 2021/02/04 08:20:41 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_print_numbers(void) {
	int number = 48;

	for (int i = 0; i < 10; i++) {
		write(1, &number, 1);
		number++;
	}
}

int main() {
	ft_print_numbers();
}
