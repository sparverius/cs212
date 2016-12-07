/* writetext.c
 * Richard Kent
 * opens file 'names.txt', writes a list of names(one on each line)
 */

#include <stdio.h>

FILE *file_p;

int main(void) {
	file_p = fopen("names.txt", "w");
	char* text = "Alice\nMad Hatter\nCheshire Cat\nWhite Rabbit\n";
	fputs(text, file_p);
	fclose(file_p);
	return 0;
}
