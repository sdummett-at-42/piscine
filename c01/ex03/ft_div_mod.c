#include <stdio.h>

void ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b; 
	*mod = a % b;
}

int main()
{
	int a = 9;
	int b = 6;
	int div;
	int mod; 

	printf("Before calling funtion, a = %d, b = %d, div = %d, mod= %d\n", a, b, div, mod);
	ft_div_mod(a, b, &div, &mod);
	printf("After calling functino, a = %d, b = %d, div = %d, mod = %d\n", a, b, div, mod);

}
