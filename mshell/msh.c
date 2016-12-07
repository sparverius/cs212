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

  signal(SIGINT, SIG_IGN);
  signal(SIGQUIT, SIG_IGN);

  while(1) {
    printf("|msh> ");
    getline(&input_line, &line_size, stdin);

    command_stoa(command, input_line);

    if (!strcmp(command[0], "exit")) {
      free(input_line);
      exit(0); 
    }
    if (command[1] && strcmp(command[1], "|") == 0) {
      m_pipe(command[0], command[2]);
      continue;
    }
    if (!strcmp(command[0], "mcd")) {
      mcd(command[1]);
      continue;
    }
     
    cmd_pid = fork();

    if (cmd_pid == 0) {
      signal(SIGINT, SIG_DFL); 
      signal(SIGQUIT, SIG_DFL);
//      command_stoa(command, input_line);
//      printf("HEY\n");
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

void mcd(char *path) {
  chdir(path);
}

void m_pipe(char *in, char* out) {
 const char* n_in = (const char*) in;
 const char*  n_out = (const char*) out;
 execlp("mpipe0", "mpipe0", n_in, n_out, (char *) NULL);
 // FILE *p_in, *p_out;
 // char buf;
 // p_in = popen(in, "r");
 // p_out = popen(out, "w");
// 
 // while (buf = fgetc(p_in))
 //   fputc(buf, p_out);
 // pclose(p_in);
 //pclose(p_out);
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
