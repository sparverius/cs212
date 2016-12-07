/* add1.c
 * Richard Kent
 * function header before and definition after main method
 */
#include <stdio.h>

int add(int n1, int n2);

int main(void) {
	int a = 42;
	int b = 84;

	int c = add(a,b);
	printf("The sum of %d and %d is %d\n",a,b,c);
}

int add(int n1, int n2) {
	int sum;
	sum = n1 + n2;
	return sum;
}
