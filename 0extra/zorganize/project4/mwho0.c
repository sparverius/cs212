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
int  tv_sec;

//extern struct utmp one;

///int open(const char *pathname, int flags);
//int printf(char* format, ...);

int main(void) {

  int counter; 
  FILE *ptr_file;
  struct utmp my_utmp;
  //struct timeval my_ut_tv;

  ptr_file = fopen("utmp","r"); 
  for (counter=1; counter <= 10; counter++) {
    fread(&my_utmp, sizeof(struct utmp),1, ptr_file);
    //printf("%s\n", my_utmp.ut_user);
    int times = my_utmp.ut_tv.tv_sec;
    printf("%-9s%-4s%-10s%d\n", my_utmp.ut_user, my_utmp.ut_line, my_utmp.ut_id, my_utmp.ut_tv.tv_sec);
  }

  //open("utmp", 0);
  //read(3, &ut_user, UT_NAMESIZE);
  //write(1, &ut_user, UT_NAMESIZE);
  //printf("%s", one.getutent());
  //printf(name);
}
