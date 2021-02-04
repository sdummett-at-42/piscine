#include <stdio.h>

char *ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		if (src[i + 1] == '\0')
			dest[i + 1] = '\0';
		i++;
	}
	return(dest);	
}

int main()
{
	char str[] = "jsdhfiusdhfi";
	char dest[] = "";

	printf("Before calling function, str = %s, dest = %s\n", str, dest);
	printf("strcpy:%s\n", ft_strcpy(dest, str));
	printf("After calling function, str = %s, dest = %s\n", str, dest);
	return(0);
}
