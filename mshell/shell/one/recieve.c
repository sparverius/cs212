#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  char input[256];
  fgets(input, sizeof(input), stdin);
  printf("FILE: %s  RECEIVE: %s", argv[0],input);
  return 0;
}
