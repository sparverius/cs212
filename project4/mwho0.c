/* mwho0.c
 * Richard Kent
 * A version of the who command.
 */
//#include <stdio.h>
#include <utmp.h>

int read(int fd, void *buf, int count);
int open(const char *pathname, int flags);
int printf(char* format, ...);

short ut_type;
char ut_user[UT_NAMESIZE];
char ut_host[UT_HOSTSIZE];
char ut_line[UT_LINESIZE];
char ut_id[4];
unsigned long  tv_sec;

int main(void) {
  struct utmp my_utmp;
  open("/var/run/utmp", 0);
  while(read(3, &my_utmp, sizeof(struct utmp))) {
    if (my_utmp.ut_type == 7) {
      printf("%-9s%-13s%-10d %s\n", my_utmp.ut_user, my_utmp.ut_line, my_utmp.ut_tv.tv_sec, my_utmp.ut_host);
    }
  }

}
