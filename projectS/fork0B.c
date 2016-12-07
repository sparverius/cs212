/* fork0B.c
 * Richard Kent
 */

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(void) {
  printf("before forks: program process ID is %d\n", (int) getpid());
  fork();
  printf("between forks: process program ID is %d\n", (int) getpid());
  fork();
  printf("after forks: program process ID is %d\n", (int) getpid());
}
