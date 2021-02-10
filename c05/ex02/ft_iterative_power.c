/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 15:12:13 by sdummett          #+#    #+#             */
/*   Updated: 2021/02/10 15:12:14 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_iterative_power(int nb, int power)
{
	int n;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	n = nb;
	while (power > 1)
	{
		nb = nb * n;
		power--;
	}
	return (nb);
}
