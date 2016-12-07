/* math.c
 * Richard Kent
 * program that uses a math function i.e. sqrt()
 */
#include <stdio.h>
#include <math.h>

int main(void) {
	int a; //user input
	scanf("%d", &a);
	printf("%d is your number and the square root is %g\n", a, sqrt(a));
	return 0;
}
