/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 08:30:19 by sdummett          #+#    #+#             */
/*   Updated: 2021/02/05 08:45:48 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
int ft_str_is_alpha(char *str)
{
	int i;
	
	i = 0;
	if (str[i] == '\0')
		return(1);
	while (str[i] != '\0')
	{
		if (str[i] < 'a' || str[i] > 'z')
			if (str[i] < 'A' || str[i] > 'Z')
				return(0);
		i++;
	}
	return(1);
}

int main()
{
	char str[] = "azAZ";

	printf("return:%d\n",ft_str_is_alpha(str));
}
