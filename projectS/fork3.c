/* fork3.c 
 * Richard Kent
 * fork and exec together!
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {
  int pid;
  char* message;
  int count;
  int speed;
  printf("Forking now\n");
  pid = fork();

  if (pid == 0) {
    char* args[3];
    args[0] = "ps"; args[1] = "-l"; args[2] = 0;

    write(1, "Get ready!\n\n", 12);
    execvp("ps", args);
    
    message = "I am the child!";
    count = 3;
    speed = 2; 
  } else { // parent gets child's pid
    message = "I am the parent!";
    count = 3;
    speed = 2;
  }

  while(count > 0) {
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
