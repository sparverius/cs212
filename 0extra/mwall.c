
#include <stdlib.h>
#include <utmp.h>
#include <unistd.h>
#include <time.h>
#include <stdio.h>
#include <string.h>

int open(const char *pathname, int flags);
void write2();

int main(void) {
//  char buff[1024];
  char* buff = (char *) malloc(80L);
  memset(buff, 0, 80);
  char buff2;
  int i = 0;
  while(read(0, &buff2, 1)) {
    buff[i] = buff2; 
    i++; 
  }
//  buff[i] = '\0';

  struct utmp mutmp;
  open("/var/run/utmp", 0);
  while( read(3, &mutmp, sizeof(struct utmp))) {
    if (mutmp.ut_type == 7 && mutmp.ut_line[0] != 't') {
      char *line = mutmp.ut_line;
      char buffer[32];
      strcat(buffer,"/dev/");
      strcat(buffer, line);
      int fd = open(buffer, 2);
      i = 0;
      while (buff[i] != '\0') {
        write(fd, &buff[i], 1);
        i++;
      }
      close(fd);
      memset(buffer, 0, 32);
    }
  }

  free(buff);
}
