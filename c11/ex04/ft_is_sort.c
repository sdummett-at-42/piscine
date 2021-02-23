/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 21:10:52 by sdummett          #+#    #+#             */
/*   Updated: 2021/02/23 19:16:16 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int i;

	i = 0;
	if (f(tab[i], tab[length - 1]) > 0)
		while (i < length - 1)
		{
			if (f(tab[i], tab[i + 1]) < 0)
				return (0);
			i++;
		}
	else if (f(tab[i], tab[length - 1]) < 0)
		while (i < length - 1)
		{
			if (f(tab[i], tab[i + 1]) > 0)
				return (0);
			i++;
		}
	else
		while (i < length - 1)
		{
			if (f(tab[i], tab[i + 1]) != 0)
				return (0);
			i++;
		}
	return (1);
}
