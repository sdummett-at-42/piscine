#include <unistd.h>

int main(){
	int e = 77;
	char c = e;
	write(1, &c, 1);
}
