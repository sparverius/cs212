/* waiting0.c
 * Richard Kent
 * illustrates use of new system call: wait
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NAP_TIME 5

int main(void) {
  int pid;
  printf("starting: pid is %d\n", getpid()); // note new system call

  pid = fork();

  if (pid == 0) { // child: pid = 0
    printf("child id: %d. Child napping for %d seconds\n", getpid(), NAP_TIME);
    sleep(NAP_TIME);
    printf("nap over; child exiting\n");
    exit(42);
  } else {  // parent: pid > 0
    int wait_result;
    printf("Parent (id: %d) starts waiting until child's nap over\n", getpid());
    //sleep(NAP_TIME);
    wait_result = wait(NULL);
    printf("Parent (id: %d) done waiting for child (id: %d) wait_result = %d\n", getpid(), pid,
    wait_result);
  }
  return 0;
}
