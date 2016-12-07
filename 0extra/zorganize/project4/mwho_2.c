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
/////unsigned int t



int write(int fd, const void *buf, size_t count);
int read(int fd, void *bf, size_t count);
int open(const char *pathname, int flags);
//int printf(char* format, ...);
char *ctime(const time_t *timep);

int main(void) {

  struct utmp my_utmp;
  struct timeval ut_tv;
  struct timezone tz;
  open("utmp", 0);
  while (read(3, &my_utmp, sizeof(struct utmp))) {
   if (my_utmp.ut_type != USER_PROCESS)
      return;
    write(1, &my_utmp.ut_user, sizeof(ut_user));
    write(1, "\t", 1);
    write(1, &my_utmp.ut_line, sizeof(ut_line));
    write(1, "\t", 1);
   // read(3, &my_utmp.ut_tv.tv_sec, sizeof(tv_sec));
    //char *one = gettimeofday(&my_utmp.ut_tv, &tz);
    //long t = time(my_utmp.ut_tv.tv_sec);
    
    //write(1, ctime(&t), sizeof(t));
    //char *cp;
    
    

    //cp = ctime(&my_utmp.ut_tv.tv_sec);
    //printf("%12.12s", cp+4);
    //write(1, &cp, sizeof(cp));
    //write(1, &my_utmp.ut_time, sizeof(long));
    write(1, "\n", 1);
    
  }
  //printf("%d", my_utmp.ut_tv.tv_sec);
}
