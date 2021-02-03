#include <stdio.h>

void ft_ultimate(int *********nbr)
{
	*********nbr = 42;
}

int main()
{
	int n = 20;
	int *a = &n;
	int **b = &a;
	int ***c = &b;
	int ****d = &c;
	int *****e = &d;
	int ******f = &e;
	int *******g = &f;
	int ********h = &g;

	printf("n = %d\n", n);
	ft_ultimate(&h);
	printf("n = %d\n", n);
}
