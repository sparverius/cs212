/* pipe2.c
 * parent writes and reads to pipe; child just writes
 */

#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define SIZE 100

int main(void) {
  int the_pipe[2];
  char* parent = "Where are those cookies going?\n";
  char* child = "Tasty ... Tasty ...\n";
  char buffer[SIZE];
  int wlen, rlen;

  pipe(the_pipe);
  printf("Read(out) fd: %d and Write(in) fd %d\n",
                    the_pipe[0], the_pipe[1]);
  
  if (fork() > 0) {
    wlen = strlen(parent);
    while(1) {
      write(the_pipe[1], parent, wlen);
      sleep(1);
      rlen = read(the_pipe[0], buffer, SIZE);
      if (rlen <=0)
        break;
      write(1, buffer, rlen);
    }
  } else {
    wlen = strlen(child);
    while(1) {
      write(the_pipe[1], child, wlen);
      sleep(3);
    }
  }
  return 0;
}
