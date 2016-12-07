/* msh10.c
 * Richard Kent
 * a mini shell continued.
 * Ignores SIGINT & SIGQUIT
 * and has built-in command 'exit'
 * Also has built-in cd command;
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <sys/wait.h>

#include <signal.h>

#define CMD_LENGTH 100
#define TOKENS 10


void command_stoa(char** command, char* command_text);
void mcd(char *path);
void m_pipe(char *in,char *out);


int main(void) {
  long line_size = CMD_LENGTH;
  char* input_line;
  input_line = (char*) malloc(CMD_LENGTH + 1);

  char* command[TOKENS];
  int cmd_pid;
  int cmd_status;

  int ispipe = 0;
  int _pipe[2];
  int _fd, _pid;

  signal(SIGINT, SIG_IGN);
  signal(SIGQUIT, SIG_IGN);

  while(1) {
    printf("|msh> ");
    getline(&input_line, &line_size, stdin);
    command_stoa(command, input_line);
    if (!strcmp(command[0], "exit")) {
//      free(input_line);
      exit(0); 
    }
    if (!strcmp(command[0], "mcd")) {
      mcd(command[1]);
      continue;
    }
    if (command[1] && strcmp(command[1], "|") == 0) {
      ispipe = 1;
    }
    cmd_pid = fork();
      
    if (cmd_pid == 0) {
      signal(SIGINT, SIG_DFL); 
      signal(SIGQUIT, SIG_DFL);
//      command_stoa(command, input_line);
      if (ispipe) {
        pipe(_pipe);
        _pid = fork();
        if (_pid > 0) {
          close(_pipe[1]);
          dup2(_pipe[0], 0);
          close(_pipe[1]);
          execlp(command[2], command[2], (char *) NULL);
        }
        else {
          close(_pipe[0]);
          dup2(_pipe[1], 1);
          close(_pipe[1]);
          execlp(command[0], command[2], (char *) NULL);
        }
      } else { 
        execvp(command[0], command);
      } 
    }
    else {
      wait(&cmd_status);
    }
    ispipe = 0;
    while (waitpid(-1, NULL, WNOHANG) > 0)
      ; 
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

void mcd(char *path) {
  chdir(path);
}

void m_pipe(char *in, char* out) {
 //  int _pipe[2];
 //  int fd, pid;
 //  pipe(_pipe);
 //  pid = fork();
 //  if (pid > 0) {
 //    close(_pipe[1]);
 //    dup2(_pipe[0], 0);
 //    //close(_pipe[0]);
 //    execlp(out, out, NULL);
 //  }
 //  else {
 //    close(_pipe[0]);
 //    dup2(_pipe[1], 1);
 //    //close(_pipe[1]);
 //    execlp(in, in, NULL);
 //  }
}
