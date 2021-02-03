#include <stdio.h>

void ft_ft(int *nbr)
{
	*nbr = 42;
}

int main()
{
	int n = 10;

	printf("1.n = %d\n", n);
	ft_ft(&n);
	printf("2.n = %d\n", n);
}
