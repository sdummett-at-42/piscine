#include <unistd.h>

void ft_print_reverse_alphabet(void) {
	int letter = 122;

	for (int i = 0; i < 26; i++) {
		write(1, &letter, 1);
		letter--;
	}
}

int main() {
	ft_print_reverse_alphabet();
}
