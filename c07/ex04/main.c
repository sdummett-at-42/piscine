/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 18:55:58 by sdummett          #+#    #+#             */
/*   Updated: 2021/02/22 19:51:08 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
char *ft_convert_base(char *nbr, char *base_from, char *base_to);

int main()
{
	char nbr[] = "++++++++++-++1111011++++++-0";
	char base_from[] = "01";
	char base_to[] = "0123456789abcdef";
	printf("res:>%s<\n",ft_convert_base(nbr, base_from, base_to));

}
