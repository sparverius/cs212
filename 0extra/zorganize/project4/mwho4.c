/* mwho0.c
 * Richard Kent
 * A version of the who command.
 */
//#include <stdio.h>
#include <utmp.h>
#include <time.h>

short int ut_type;
char ut_user[UT_NAMESIZE];
char ut_line[UT_LINESIZE];
char ut_id[4];
unsigned long  tv_sec;



//char *ctime(const long *timep);
int read(int fd, void *buf, int count);
int open(const char *pathname, int flags);
int printf(char* format, ...);

int main(void) {
  struct utmp my_utmp;
    open("/var/run/utmp", 0);
    while(read(3, &my_utmp, sizeof(struct utmp))) {
        // long times = my_utmp.ut_tv.tv_sec;
        //char *cp;
        //cp = ctime(&times);
        unsigned long times = my_utmp.ut_tv.tv_sec;
        struct tm *info;
        char buffer[80];
        //time( &times);
        info = localtime( &times);
        strftime(buffer, 80, "%Y-%m-%d %I:%M", info);


        printf("%-9s%-13s%-10s\n", my_utmp.ut_user, my_utmp.ut_line, buffer);
  }

}
