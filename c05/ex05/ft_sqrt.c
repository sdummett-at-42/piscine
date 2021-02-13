/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 15:12:46 by sdummett          #+#    #+#             */
/*   Updated: 2021/02/13 08:57:07 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int sqrt;

	if (nb == 1)
		return (1);
	else if (nb < 1)
		return (0);
	sqrt = 1;
	while (sqrt <= nb / 2)
	{
		if (sqrt * sqrt > nb)
			return (0);
		if (sqrt * sqrt == nb)
			return (sqrt);
		sqrt++;
	}
	return (0);
}
