/* typedefs.c
 * Richard Kent
 * illustrates the use of typedef
 */
#include <stdio.h>

typedef int status_t;

int main(void) {
	status_t health = 10;
	status_t strength = 8;
	printf("\nJoe's health is %d, and\n his strength"
	       " is %d\n\n", health, strength);
	return 0;
}
