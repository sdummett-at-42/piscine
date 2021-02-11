/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 15:12:58 by sdummett          #+#    #+#             */
/*   Updated: 2021/02/11 15:07:42 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int n;

	if (nb == 0 || nb == 1)
		return (0);
	if (nb == 2)
		return (1);
	n = 2;
	while (n < nb)
	{
		if (nb % n == 0)
			return (0);
		n++;
	}
	return (1);
}

#include <stdio.h>
int main()
{
	int nb = -2147483647;
	printf("%d\n", ft_is_prime(nb));
}
