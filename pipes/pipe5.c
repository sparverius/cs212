/* pipe2.c
 * parent writes and reads to pipe; child just writes
 */

#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char* argv[]) {
  int pid, fd;
  pid = fork();
  if (pid == 0) {
    close(1);
    fd = creat(argv[2], 0644);
    execlp(argv[1], argv[1], NULL);
  }
  if (pid != 0) {
    wait(NULL);
  }
  return 0;
}
