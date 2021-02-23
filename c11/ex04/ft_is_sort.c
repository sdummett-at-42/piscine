/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 21:10:52 by sdummett          #+#    #+#             */
/*   Updated: 2021/02/23 17:17:48 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
int		ft_strcmp(int s1, int s2)
{
	if (s1 < s2)
		return (-11);
	else if (s1 >  s2)
		return (99);
	else 
		return (0);

}

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int i;

	printf("%d\n", length);
	i = 0;
	while (i < length - 1)
	{
		printf("%d\n", i);
		if (f(tab[i], tab[i + 1]) == 0)
		{
			printf("== 0\n");
			i++;
		}
		else if (f(tab[i], tab[i - 1]) > 0)
		{
			while ((f(tab[i], tab[i + 1]) > 0 || f(tab[i], tab[i + 1]) == 0) && i < length - 1)
			{
				printf("yo");
				i++;
			}
			if (i != length - 1)
				return (0);
			else
				return (1);
		}
		else if (f(tab[i], tab[i + 1]) < 0)
		{
			while ((f(tab[i], tab[i + 1]) < 0 || f(tab[i], tab[i + 1]) == 0) && i < length - 1)
				i++;
			if (i != length - 1)
				return (0);
			else
				return (1);
		}
	}
	return (1);
}


int main()
{
	int tab[26] = {7, 7, 7, 7, 6, 6, 6, 6, 5, 5, 4, 3, 3, 3, 3, 3, 3, 3, 2, 2, 2, 2, 2, 1, 1, 1};
	//int tab[6] = {1,2,3,4,5,6};
	printf("ret:%d\n", ft_is_sort(tab, 26, &ft_strcmp));
}
