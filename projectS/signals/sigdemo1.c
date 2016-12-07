/* sigdemo1.c
 * This program's behaviour is different if compiled with C99.
 * Compare the behaviour with both
 * 1. gcc sigdemo1.c -o sigdemo1
 * 2. gcc -std=c99 sigdemo1.c -o sigdemo1
 */

#include <stdio.h>    // for printf
#include <signal.h>   // for signal and SIGINT
#include <unistd.h>   // for sleep

void handler(int signum);

int main(void) {

  signal(SIGINT, handler);
  // this system call makes handler() the response to SIGINT
  // does not reset in C99 just 1 call

  while(1) {
    printf("hello\n");
    sleep(1);
  }
}


void handler(int signum) {
  printf("OUCH!\n");
  signal(SIGINT, handler);
  /* this resets handler to handle more calls with C99 */
}
