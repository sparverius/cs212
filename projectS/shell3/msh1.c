/* msh1.c
 * Richard Kent
 * towards a small command interpreter:
 * demonstrates strtok
 *    strtok is a string tokenizer
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

  int bytes_in_line;
  char* input_line;
  //int line_length = 100;
  long line_length = 100;

  input_line = (char *) malloc(line_length + 1);

  printf("|msh> ");
  bytes_in_line = getline(&input_line, &line_length, stdin);

  printf("%s\n", input_line);

  char* command[10];
  char* token;
  token = strtok(input_line, " ");                        // usefull string.h function
  printf("%s\n", token);
  token = strtok(NULL, " ");
  printf("%s\n", token);
}
