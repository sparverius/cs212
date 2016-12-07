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
//unsigned int tv_sec;
//long ut_time;


int write(int fd, const void *buf, size_t count);
int read(int fd, void *bf, size_t count);
int open(const char *pathname, int flags);
//int printf(char* format, ...);
char *ctime(const time_t *timep);
time_t time(time_t *tloc);

void show( time_t timeval);//struct utmp *bufp);
void info( struct utmp *buf);


int main(void) {

  struct utmp my_utmp;
  //struct timeval ut_tv;
  
  open("utmp", 0);

  while (read(3, &my_utmp, sizeof(struct utmp))) {
   //if (my_utmp.ut_type != USER_PROCESS)
   //   return;
//    write(1, &my_utmp.ut_user, sizeof(ut_user));
//    write(1, "\t", 1);
//    write(1, &my_utmp.ut_line, sizeof(ut_line));
//    write(1, "\t", 1);
   // //long t = time(my_utmp.ut_tv.tv_sec);
    
   // //write(1, ctime(&t), sizeof(t));
   // char *cp;
   // cp = ctime(&my_utmp.ut_tv.tv_sec);
   // //printf("%12.12s", cp+4);
   // write(1, &cp, sizeof(cp));
   
   //long *cp;
   
   //long timev = my_utmp.ut_time;
   
  info(&my_utmp);

   //cp = ctime(&timev);
   
   //cp = time(timev);
   //write(1, cp,100);

///write(1, cp+4, 16);

write(1, "\n", 1);
    //show(&my_utmp);
  }
  //printf("%d", my_utmp.ut_tv.tv_sec);
}


void info( struct utmp *buf) {
  show( buf->ut_time);
  //printf("%10ld", buf->ut_time);
}


void show( time_t timeval) {//struct utmp *bufp) {

  //time_t time();
  char *cp;
  printf("%ld", time(&timeval));
  //printf("%s", cp);

//  printf("%s", (*bufp).ut_time);

}
