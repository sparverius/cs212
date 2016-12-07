#include <stdio.h>

int number;
void pyramid(int num);

int main(void) {

	scanf("%d", &number);
	pyramid(number);
	return 0;
}

void pyramid(int num) {
	for (int i = 2; i <= num; i++) {
		for (int j = 0; j < num-i; j++) {
			printf("%c",' ');
		}
		for (int k = 0; k < i; k++) {
			printf("%c", '#');
		}
		printf("%c", '\n');		
	}
}
