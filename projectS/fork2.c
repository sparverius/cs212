/* fork2.c
 * Richard Kent
 * forking again!
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int pid;
  char* message;
  int count;
  int speed;

  printf("Forking now\n");
  pid = fork();

  if(pid == 0) {
    message = "I am the child!";
    count = 9;
    speed = 1;
  } else { // parent gets child'd pid
    message = "I am the parent!";
    count = 3;
    speed = 2;
  }

  while (count > 0) {
    printf("%s", message);
    printf("\n");
    sleep(speed);
    count--;
  }

  if (pid == 0) {
    printf("Child leaving now!\n");
  } else {
    printf("Parent leaving now!\n");
  }
  exit(0);
}
