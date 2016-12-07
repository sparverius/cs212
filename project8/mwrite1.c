/* mwrite1.c
 * Richard Kent
 * Checks if the target user is logged in at specified terminal.
 */

#include <utmp.h>

int read(int fd, void *buf, int count);
int open(const char *pathname, int flags);
int printf(const char * format, ...);
int write(int fd, const void *buf, int count);

int mstrcmp(const char *one, const char *two);

short ut_type;
char ut_user[UT_NAMESIZE];
char ut_host[UT_HOSTSIZE];
char ut_line[UT_LINESIZE];
char ut_id[4];
unsigned long tv_sec;

int main(int argc, char *argv[]) {
  struct utmp my_utmp;
  open ("/var/run/utmp", 0);
  while(read(3,&my_utmp,sizeof(struct utmp))) {
    
    if (my_utmp.ut_type == 7) {
      char *user = my_utmp.ut_user;
      if (argv[1] && argv[2]) { 
        if(!mstrcmp(user, argv[1])) {
          if (!mstrcmp(my_utmp.ut_line, argv[2]+5)) {
            open(argv[2], 2);
            char one;
            write(4, "\n",1);
            while(read(0, &one, 1)) {
              write(4, &one, 1);
            }
          }
        } else {
          printf("mwrite1: %s is not logged on\n", argv[1]);
        }
      } else {
        printf("%s", "usage: mwrite1 user [tty]\n");
      }
    }
  }
}

int mstrcmp(const char *one, const char *two) {
  int retur = 0;
  while(!(retur = *(unsigned char *) one - *(unsigned char *)two) && *two) ++one, ++two;
  if (retur < 0) {
    retur = -1;
  } else if (retur > 0) {
    retur = 1;
  }
  return retur;
}
