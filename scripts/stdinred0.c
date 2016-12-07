/* stdinred0.c
 * redirects standard input to come from different sources
 */

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int close(int fd);

int main(void) {
  int fd;
  long count = 100;
  char* line;
  line = (char *) malloc(100);

  // stdin is open and refers to keyboard
  getline(&line, &count, stdin); printf("%s", line);
  getline(&line, &count, stdin); printf("%s", line);
  getline(&line, &count, stdin); printf("%s", line);
  printf("\n");

  close(0); // closes stdin
  fd = open("passwd", O_RDONLY);
  printf("fd = %d\n", fd);
  getline(&line, &count, stdin); printf("%s", line);
  getline(&line, &count, stdin); printf("%s", line);
  getline(&line, &count, stdin); printf("%s", line);
  printf("\n");
  fflush(stdin);    // necessary to clean out stdin buffer
                    // try commenting out this line

  close(0);
  fd = open("stdinred0.c",  O_RDONLY);
  printf("fd = %d\n", fd);

  getline(&line, &count, stdin); printf("%s", line);
  getline(&line, &count, stdin); printf("%s", line);
  getline(&line, &count, stdin); printf("%s", line);
  printf("\n");

  return 0;
}
