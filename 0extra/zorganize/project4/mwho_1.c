/* mwho0.c
 * Richard Kent
 * A version of the who command.
 */
#include <stdio.h>
#include <utmp.h>

short int ut_type;
char ut_user[UT_NAMESIZE];
char ut_line[UT_LINESIZE];
char ut_id[4];
int32_t tv_sec;

int write(int fd, const void *buf, size_t count);
int read(int fd, void *bf, size_t count);
int open(const char *pathname, int flags);
//int printf(char* format, ...);
//char *ctime(const time_t *timep);

int main(void) {

  struct utmp my_utmp;
  struct timeval ut_tv;

  open("utmp", 0);
  while (read(3, &my_utmp, sizeof(struct utmp))) {
    int *t = &my_utmp.ut_tv.tv_sec;
    write(1, &my_utmp.ut_user, sizeof(ut_user));
    write(1, "\t", 1);
    write(1, &my_utmp.ut_line, sizeof(ut_line));
    //char *times = ctime(my_utmp.ut_tv.tv_sec);
    
    write(1, "\t", 1);
    write(1, &my_utmp.ut_tv, sizeof(tv_sec));
    write(1, "\n", 1);
  }
    printf("%d", my_utmp.ut_tv.tv_sec);
}
