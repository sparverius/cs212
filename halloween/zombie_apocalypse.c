/* zombie_apocalypse.c
 * Richard Kent
 * zombies take over your computer !
 */

#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>

int main(void) {
  int pid;
  char* message;
  int count = 0;
  int time_to_sleep;

  while(1) {
    printf("Forking now\n");
    pid = fork();

    if (pid == 0) {
      message = "Child with ";
      printf("%s pid :%d", message, getpid());
      printf("Child %d becomes zombie now", getpid());
      exit(42);
    }
    else {
      message = "Oh no! My children are becoming zombies!";
      printf("%s pid : %d", message, getpid());
      count++;
    }
  }
  exit(0);
}

