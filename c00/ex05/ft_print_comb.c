#include <unistd.h>
#include <stdio.h>

void ft_print_comb(void) {
	int d = 0;
	int e = 0;
	int f = 0;
	char c;

	while (d < 10) {
		e = d + 1;
		while (e < 10) {
			f = e + 1;
			while (f < 10) {
				if (f != 9 || e != 8 || d != 7){
					printf("%d%d%d, ", d, e, f);
				}
				else {
					printf("%d%d%d", d, e, f);
				}
				f++;
			}
			e++;
		}
		d++;
	}
}

int main() {
	ft_print_comb();
}
