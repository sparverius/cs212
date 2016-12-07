/* msh7.c
 * Richard Kent
 * a mini shell
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <sys/wait.h>

#define CMD_LENGTH 100
#define TOKENS 10

void command_stoa(char** command, char* command_text);

int main(void) {
  long line_size = CMD_LENGTH;
  char* input_line;
  input_line = (char*) malloc(CMD_LENGTH + 1);

  char* command[TOKENS];
  int cmd_pid;
  int cmd_status;

  while(1) {
    printf("|msh> ");
    getline(&input_line, &line_size, stdin);

    cmd_pid = fork();

    if (cmd_pid == 0) {
      command_stoa(command, input_line);
      execvp(command[0], command);
    }
    else {
      wait(&cmd_status);
    }
  }
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
