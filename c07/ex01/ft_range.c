/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 13:56:17 by sdummett          #+#    #+#             */
/*   Updated: 2021/02/13 14:59:06 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
int *ft_range(int min, int max)
{
	int *tab = NULL;

	if (min >= max)
		return (tab);
	return(tab);

}

int main()
{
	int min;
	int max;
	int size;
	int *tab;

	min = -600;
	max = -700;
	if (min > max)
		printf("MIN > MAX");
	if (min < 0)
		if (max < 0)
			size = min + (max * -1);
	//printf("tab:>%s<", ft_range(min, max));
}
