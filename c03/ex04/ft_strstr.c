/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 14:07:13 by sdummett          #+#    #+#             */
/*   Updated: 2021/02/07 15:30:34 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strstr(char *str, char *to_find)
{
	int i;
	if (*to_find == '\0')
		return (str);
	while (*str != '\0')
	{
		i = 0;
		while (str[i] == to_find[i] && str[i] != '\0' && str[i] != '\0')
		{
			if (to_find[i + 1] == '\0')
				return (str);
			i++;
		}

		str++;

	}
	return (NULL);
}
int main()
{
	char meule_de_foin[] = "2452452456123";
	char aiguille[] = "12";
	
	printf("strstr>%s<ft_strstr>%s<\n", strstr(meule_de_foin, aiguille), ft_strstr(meule_de_foin, aiguille));
}

