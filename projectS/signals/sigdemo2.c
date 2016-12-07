/* sigdemo2.c
 * This program ignores SIGINT
 */

#include <stdio.h>    // for printf
#include <signal.h>   // for signal and SIGINT
#include <unistd.h>   // for sleep

int main(void) {

  signal(SIGINT, SIG_IGN);
  printf("You can't stop me!\n");
  while(1) {
    sleep(1);
    printf("haha\n");
  }
}
