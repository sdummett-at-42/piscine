#include <string.h>
#include <stdio.h>

char *ft_strncpy(char *dest, char *src, size_t n)
{
	size_t i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		if (i + 1 == n || src[i] == '\0')
			dest[i + 1] = '\0';
		i++;
	}
	return(dest);
}

int main()
{
	char str[] = "12Sto2ne test";
	char dest[] = "";
	int n;
	n = 6;
	printf("result :%s\n", ft_strncpy(dest, str, n));
}
