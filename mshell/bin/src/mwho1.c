/* mwho0.c
 * Richard Kent
 * A version of the who command.
 */
//#include <stdio.h>
#include <utmp.h>
#include <time.h>
#include <string.h>

int read(int fd, void *buf, int count);
int open(const char *pathname, int flags);
int printf(char* format, ...);

short int ut_type;
char ut_user[UT_NAMESIZE];
char ut_host[UT_HOSTSIZE];
char ut_line[UT_LINESIZE];
char ut_id[4];
pid_t ut_pid;
int ut_session;
short ut_type;
unsigned long  tv_sec;
char p1, p2;

int main(void) {
  struct utmp my_utmp;
  open("/var/run/utmp", 0);
  while(read(3, &my_utmp, sizeof(struct utmp))) {
    if (my_utmp.ut_type == 7) {
      unsigned long times = my_utmp.ut_tv.tv_sec;
      struct tm *info;
      char buffer[80];
      info = localtime( &times);
      strftime(buffer, 80, "%Y-%m-%d %H:%M", info);
      if ( strlen(my_utmp.ut_host) != 0) {
        p1 = '(';
        p2 = ')';
      } else {
        p1 = p2 = ' ';
      }
      printf("%-9s%-13s%-10s %c%s%c\n", my_utmp.ut_user, my_utmp.ut_line, buffer, p1, my_utmp.ut_host ,p2);
    }
  }

}
