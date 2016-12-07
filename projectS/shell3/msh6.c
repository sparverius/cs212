/* msh6.c
 * Richard Kent
 * parent waits for its child process prints command exit status
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
  input_line = (char *) malloc(CMD_LENGTH + 1);

  char* command[TOKENS];
  int cmd_pid;
  int cmd_status;
  int high_8, low_7, bit_7;
  
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
      high_8 = cmd_status >> 8;       /* 1111 1111 0000 0000 */
      low_7 = cmd_status & 0x7F;      /* 0000 0000 0111 1111 */
      bit_7 = cmd_status & 0x80;      /* 0000 0000 1000 0000 */
      printf("cmd status: exit code = %d, signal = %d, core dump? = %d\n", high_8, low_7, bit_7);
    }
  }
}

void command_stoa(char** command, char* command_text) {
  char* token = strtok(command_text, " ");
  int token_index = 0;
  while (token != NULL) {
    command[token_index] = token;
    token = strtok(NULL, " ");
    token_index++;
  }

  char * last_token = command[token_index - 1];
  int length = strlen(last_token);
  last_token[length - 1] = 0;
  command[token_index] = 0;
}
