/* fork1.c
 * Richard kent
 */

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(void) {
  pid_t child_pid;
  printf("main program process ID is %d\n", (int) getpid());
  child_pid = fork();
  if (child_pid != 0) {
    printf("this is the parent, with ID %d\n", (int) getpid());
    printf("the childs process ID is %d\n", (int) child_pid);
  } else 
    printf("this is the child with id %d\n", (int) getpid());
}
