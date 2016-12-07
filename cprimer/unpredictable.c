/* unpredictable.c
 * Richard Kent
 * prints the value of an uninitialized local variable
 */

#include <stdio.h>

int main(void) {
	int i = 4;
	printf("Could you guess that i has the value %d\n", i);
	int j = 0x12323;
	printf("What about the value in j: %d\n", j);
	printf("i = %d and j = %x", i, j);	
	return 0;
}
