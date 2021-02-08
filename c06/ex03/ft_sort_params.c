#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

//maybe I need to write a strcmp function to sort the params
int	main(int argc, char *argv[])
{
	return (0);
}
