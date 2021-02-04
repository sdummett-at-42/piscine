/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 08:27:30 by sdummett          #+#    #+#             */
/*   Updated: 2021/02/04 08:27:36 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void ft_ultimate_div_mod(int *a, int *b)
{
	int temp;

	temp = *a / *b;
	*b = *a % *b;
	*a = temp;
}

int main()
{
	int a = 9;
	int b = 6;

	printf("Before calling function, a = %d, b = %d\n", a, b);

	ft_ultimate_div_mod(&a, &b);
	printf("After calling function, a = %d, b = %d\n", a, b);
}
