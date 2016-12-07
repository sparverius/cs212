#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>

int main(void) {
  int pid;
  char*message;
  int count;
  int time_to_sleep;

  printf("Child born now\n");
  pid = fork();

  if (pid == 0) {
    message = "I am the child!";
    count = 20;
    time_to_sleep = 2;
    printf("%s My pid is %d; My parent is %d\n", message, getpid(), getppid());
  } else {      // parent gets child's pid
    message = "I am the parent!";
    printf("%s My pid is %d \n", message, getpid());
    printf("Parent leaving; child becomes orphan ");
    exit(42);
  }

  while(count > 0) {
    printf("%s My pid is %d; My parent's pid is %d", message, getpid(), getppid());
    if (getppid() == 1) 
      printf(" I have been adopted\n");
      printf("\n");
      sleep(time_to_sleep);
      count--;
  }
  exit(0);
}
