/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 08:20:05 by sdummett          #+#    #+#             */
/*   Updated: 2021/02/04 08:20:07 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_print_alphabet(void) {
	int letter = 97;

	for (int i = 0; i < 26; i++) {
		write(1, &letter, 1);
		letter++;
	}
}

int main() {
	ft_print_alphabet();
}
