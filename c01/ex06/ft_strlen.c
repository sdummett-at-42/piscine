#include <stdio.h>

int ft_strlen(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		i++;
	}
	return(i);
}

int main()
{
	int n = ft_strlen("test");

	printf("n = %d\n", n);
}
