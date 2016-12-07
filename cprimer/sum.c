/* sum.c
 * Richard Kent
 * prompts user for an integer n, prints out the sum form 1 to n
 */

//int printf(const char *format, ...);
//int scanf(const char *format, ...);

#include <stdio.h>

int main(void)
{
	int number;
	int sum;
	int i = 0;

	printf("Enter an integer: ");
	scanf("%d", &number);
	
	for(int i = 0; i <= number; i ++) {
		sum = sum + i;
	}

	printf("The sum of the first %d integers is %d\n", number, sum);
}
