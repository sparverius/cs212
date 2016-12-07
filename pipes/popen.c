/* popen.c */

#include <stdlib.h>
#include <stdio.h>

int main() {
  FILE* fcommand;
  char buffer;

  fcommand = popen("ls", "r");    // opens command as file

  while((buffer = fgetc(fcommand)) != EOF)
    printf("%c", buffer);
  pclose(fcommand);
}
