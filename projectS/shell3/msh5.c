/* msh5.c
 * Richard Kent
 * towards a small command interpreter:
 * puts command-line processing into a function
 * does the same thing msh4.c does
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define CMD_LENGTH 100
#define TOKENS 10

void command_stoa(char** command, char* command_text);

int main(void) {
  long line_size = CMD_LENGTH;
  char* input_line;
  input_line = (char*) malloc(CMD_LENGTH + 1);

  printf("|msh> ");
  getline(&input_line, &line_size, stdin);

  char* command[TOKENS];
  command_stoa(command, input_line);

  execvp(command[0], command);
}

void command_stoa(char** command, char* command_text) {
  char* token = strtok(command_text, " ");
  int token_index = 0;
  while(token != NULL) {
    command[token_index] = token;
    token = strtok(NULL, " ");
    token_index++;
  }

  char * last_token = command[token_index - 1];
  int length = strlen(last_token);
  last_token[length - 1] = 0;
  command[token_index] = 0;
}

