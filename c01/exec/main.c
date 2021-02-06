#include "myheader.h"

int main()
{
	int a = 1;
	char str[4] = "abc";
	int tab[] = {3, 2, 1};
	int size = 3;
	int i = 42;
	int *b = &i;
	int **c = &b;
	int ***d = &c;
	int ****e = &d;
	int *****f = &e;
	int ******g = &f;
	int *******h = &g;
	int ********j = &h;

	ft_ft(&a);
	ft_ultimate_ft(&j);
	ft_swap(&a, &a);
	ft_div_mod(a, a, &a, &a);
	ft_ultimate_div_mod(&a, &a);
	ft_putstr(str);
	ft_strlen(str);
	ft_rev_int_tab(tab, size);
	ft_sort_int_tab(tab, size);
}
