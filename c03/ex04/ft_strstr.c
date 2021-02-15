/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 14:07:13 by sdummett          #+#    #+#             */
/*   Updated: 2021/02/15 07:38:04 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
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
	return (0);
}
int main()
{
	printf("%s\n", ft_strstr("stone et noufel s'amusent", "noufel"));
}
