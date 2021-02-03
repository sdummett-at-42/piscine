#include <stdio.h>

void ft_swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int main()
{
	int a = 4;
	int b = 7;

	printf("Before calling function, a = %d\n", a);
	printf("Before calling function, b = %d\n", b);
	
	ft_swap(&a, &b);
	printf("After calling functin, a = %d\n", a);
	printf("After calling function, b = %d\n", b);
}
