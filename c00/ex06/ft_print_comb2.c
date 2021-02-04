/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 15:51:04 by sdummett          #+#    #+#             */
/*   Updated: 2021/02/04 08:24:00 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void ft_print_comb2(void) {
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	char e;

	while (a < 10) {
		b = 0;
		while (b < 10) {
			c = a;
			while (c < 10) {
				d = b + 1;
				while (d < 10) {
					printf("%d%d %d%d,", a, b, c, d);
					d++;
				}
				c++;
			}
			b++;
		}
		a++;
	}
}
	

int main() {
	ft_print_comb2();
}
