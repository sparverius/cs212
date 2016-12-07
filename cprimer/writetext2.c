/* writetext2.c
 * Richard Kent
 * opens the file 'names.txt' written to by writetext.c 
 * and prints out the names
 */

#include <stdio.h>

FILE *file_p;
char str[10];

int main(void) {
	file_p = fopen("names.txt", "r");
	while (	fgets(str, 10, file_p) != NULL) {
			fputs(str, stdout);
	}
	fclose(file_p);
	return 0;
}
