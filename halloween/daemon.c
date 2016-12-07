/* daemon.c
 * Richard Kent
 * creates a daemon
 */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <fcntl.h>

#include <sys/stat.h>

#include <unistd.h>

int main(void) {
  char* message;
  int pid = fork();
  if (pid == 0) {
    message = "I, the child, will become parent of the daemon";
    printf("%s\n", message);
  } else {
    message = "Parent dies so that orphaned grandchild can become daemon";
    printf("%s\n", message);
    exit(42);
  }

  setsid();
  pid = fork();
  if (pid == 0) {
    message = "I will become daemon";
    printf("%s\n", message);
  } else {
    message = "Child dies so that its child can become daemon";
    printf("%s\n", message);
    exit(42);
  }

  umask(0);
  // chdir("/");
  printf("daemon started with pid %d\n", getpid());
  close(1);
  open("daemon_log", O_RDWR);
  printf("%s", "daemon starting log\n\n");
  message = "daemon here at ";
  time_t now;
  while (1) {
    time(&now);
    printf("%s %s", message, ctime(&now));
    sleep(5);
  }
  
}

