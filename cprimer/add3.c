/*  add3.c
 *  Richard Kent
 *  illustrates pointers as parameters
 */

#include <stdio.h>

void add(int n1, int n2, int* total);

int main(void) {
	int a = 42;
	int b = 84;
	int sum;

	add(a, b, &sum);
	printf("The sum of %d and %d is %d\n", a, b, sum);
}

void add(int n1, int n2, int* total) {
	*total = n1 + n2;  	//note the use of * to write
											//to the variable that total points at
}
