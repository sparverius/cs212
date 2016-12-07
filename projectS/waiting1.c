/* waiting1.c
 * Richard Kent
 * puts child parent actions into functions
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NAP_TIME 5

void child_acts(int time);
void parent_acts(int child_pid);

int main(void) {
  int pid;
  printf("starting: pid is %d\n", getpid()); // note new system call
  
  pid = fork();

  if (pid == 0)                             // child: pid = 0
    child_acts(NAP_TIME);
  else                                      // parent: pid > 0
    parent_acts(pid);
  return 0;
}

void child_acts(int time) {
  printf("child id: %d. Child taking a nap for %d seconds\n", getpid(), time);
  sleep(time);
  printf("nap over; child exiting\n");
  exit(42);
}

void parent_acts(int child_pid) {
  int wait_result;
  printf("Parent (id: %d) starts waiting until child's nap over\n", getpid());
  wait_result = wait(NULL);
  printf("Parent (id: %d) finished waiting for child (id: %d) wait_result = %d\n", getpid(),
  child_pid, wait_result);
}
