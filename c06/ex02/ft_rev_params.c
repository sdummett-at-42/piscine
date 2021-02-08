#include <unistd.h>

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main(int argc, char *argv[])
{
	int i;
	int j;
	
	i = 1;
	while (i < argc)
	{
		j = ft_strlen(argv[i]);
		while (j >= 0)
		{
			ft_putchar(argv[i][j]);
			j--;
		}
		ft_putchar('\n');
		i++;
	}
	return (0);
}
