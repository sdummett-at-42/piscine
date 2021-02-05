#include <stdio.h>

int	ft_char_is_alpha(char c)
{
	if (c >= 'a' && c <= 'z')
		return (0);
	else if (c >= 'A' && c <= 'Z')
		return (0);
	else if(c >= '0' && c <= '9')
		return (0);
	else
		return (1);
}

char	*ft_strcapitalize(char *str)
{
	int i;

	i = 0;

	if (str[i] == '\0')
		return (str);
	if (str[i] >= 'a' && str[i] <= 'z')
	{
		str[i] -= 32;
		i++;
	}
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			if (ft_char_is_alpha(str[i - 1]) == 1)
				str[i] -=  32;
		}
		i++;
	}
	return (str);
}
