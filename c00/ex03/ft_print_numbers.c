#include <unistd.h>

void ft_print_numbers(void) {
	int number = 48;

	for (int i = 0; i < 10; i++) {
		write(1, &number, 1);
		number++;
	}
}

int main() {
	ft_print_numbers();
}
