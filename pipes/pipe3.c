/* pipe3.c
 * pipes output of 1st command to input of second
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv) {
  if (argc != 3) {
    fprintf(stderr, "Use: ./pipe3 cmd1 cmd2\n");
    fprintf(stderr, "Example: ./pipe3 ls sort\n");
    exit(1);
  }
  int the_pipe[2];
  int fd, pid;

  pipe(the_pipe);

  pid = fork();

  if (pid > 0) {          // parent
    close(the_pipe[1]);   // closed the write end of the pipe
    dup2(the_pipe[0], 0); // stdin now connects to the read end of pipe
    close(the_pipe[0]);   // the duplicate connection to read end
                          //    of pipe is broken
    execlp(argv[2], argv[2], NULL);
  } else {                // pid == 0   child
    close(the_pipe[0]);   // closed the read end of the pipe
    dup2(the_pipe[1], 1); // stdout now connects to the write end of pipe
    close(the_pipe[1]);   // the duplicate connection to write end 
                          //    of pipe broken
    execlp(argv[1], argv[2], NULL);
  }
}
