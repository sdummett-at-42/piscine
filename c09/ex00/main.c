/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 18:41:19 by sdummett          #+#    #+#             */
/*   Updated: 2021/02/22 18:50:11 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_strlen(char *str);
void ft_putchar(char c);
int ft_strcmp(char *s1, char *s2);
void ft_swap(int *a, int *b);
void ft_putstr(char *str);
#include <stdio.h>


int main()
{
	char str[] = "La";
	char str2[] = "Leeeeeggo";
	int a = 2;
	int b = 4;

	ft_putstr(str);
	ft_strcmp(str, str2);
	ft_putchar('a');
	ft_swap(&a, &b);
	printf("strlen:%d\n",ft_strlen(str));
}
