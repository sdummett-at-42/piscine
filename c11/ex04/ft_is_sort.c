/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 21:10:52 by sdummett          #+#    #+#             */
/*   Updated: 2021/02/24 18:06:19 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int i;
	int order;

	if (length == 0 || length == 1)
		return (1);
	i = 0;
	while (f(tab[i], tab[i + 1]) == 0)
		i++;
	if (f(tab[i], tab[i + 1]) < 0)
		order = 1;
	else
		order = -1;
	while (tab[i] != 0 && i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) < 0 && order == -1)
			return (0);
		else if (f(tab[i], tab[i + 1]) > 0 && order == 1)
			return (0);
		else
			i++;
	}
	return (1);
}
