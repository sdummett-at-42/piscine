/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 10:59:58 by sdummett          #+#    #+#             */
/*   Updated: 2021/02/17 11:11:13 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen(char *str)
{
	int len;

	len = 0;
	while (str[len] != 0)
		len++;
	return (len);
}

void	ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i] != 0)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

void	ft_strrev(char *str)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	j = ft_strlen(str);
	while (i < j - 1)
	{
		c = str[i];
		str[i] = str[j - 1];
		str[j - 1] = c;
		i++;
		j--;
	}
}

int		ft_base_is_manipulable(char c, char *base)
{
	int i;

	i = 0;
	while (base[i] != 0)
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (i);
}
