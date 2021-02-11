/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 15:13:11 by sdummett          #+#    #+#             */
/*   Updated: 2021/02/11 15:12:42 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_find_next_prime(int nb)
{
	int n;

	if (nb <= 0 || nb == 1 || nb == 2)
		return (2);
	while (1)
	{
		n = 2;
		while (n < nb)
		{
			if (nb % n == 0)
				break ;
			n++;
		}
		if (n == nb)
			return (nb);
		nb++;
	}
}
#include <stdio.h>
int main()
{
	int nb = -2147483647;

	printf("%d\n", ft_find_next_prime(nb));
}

