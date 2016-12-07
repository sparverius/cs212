
#include <utmp.h>
#include <unistd.h>
#include <time.h>
#include <stdio.h>
#include <string.h>

int open(const char *pathname, int flags);
void mwrite(char *tty);
void write2();

int main(void) {
  char in[1024];
//  open(0, 2);
//  while (read(0, &in, 1023)) {
 //   if (EOF) {
  //    break;
   // }
//    write2();
 // }
  write2();
}
//  read(0, &buff, 1024);
void write2() {
  struct utmp mutmp;
  open("/var/run/utmp", 0);
  while( read(3, &mutmp, sizeof(struct utmp))) {
    if (mutmp.ut_type == 7) {
      char *line = mutmp.ut_line;
      char buffer[32];
      strcat(buffer,"/dev/");
      strcat(buffer, line);
      mwrite(buffer);
      memset(buffer, 0, 32);
    }
  }
}

void mwrite(char *tty) {
  char buf[1024];
  read(1, &buf, sizeof(buf));
  open(tty,2);
  while(read(1, &buf, sizeof(buf))) {
     write(4, &buf, sizeof(buf));
  }
  write(4, &buf,sizeof(buf));
  close(4);
}
