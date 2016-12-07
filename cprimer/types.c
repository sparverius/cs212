/* types.c
 * Richard Kent
 * displays the size of int, long int, and char variable types
 */

#include <stdio.h>
#include <limits.h>

int main(void) {
	printf("\n");		//printf does not print a new line by default
	printf("Size of int %lu bytes\t", sizeof(int));
	printf("Maximum int: %d\n", INT_MAX);
	printf("Size of long %lu bytes\t",sizeof(long));
	printf("Maximum long: %ld\n", LONG_MAX);

	printf("Size of char %lu byte \t",sizeof(char));
	printf("Maximum char: %d\t", CHAR_MAX);
	printf("Minimum char: %d\n", CHAR_MIN);
	puts("");				//puts does not print a new line by default
}
