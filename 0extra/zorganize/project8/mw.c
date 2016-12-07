/* mwrite2.c
 * Richard Kent
 * Checks if the target user is logged in at specified terminal.
 */
#include <utmp.h>
#include <pwd.h>
#define NULL (void*)0
int read(int fd, void *buf, int count);
int open(const char *pathname, int flags);
int printf(const char * format, ...);
int write(int fd, const void *buf, int count);
time_t time(time_t *tloc);
char *ctime(const time_t *timep);
int close(int fd);
int atoi(const char *nptr);
char *ttyname(int fd);
struct passwd *getpwuid(uid_t uid);
int gethostname(char *name, size_t len);

int mstrcmp(const char *one, const char *two);

short ut_type;
char ut_user[UT_NAMESIZE];
char ut_host[UT_HOSTSIZE];
char ut_line[UT_LINESIZE];
char *ut_id;
unsigned long tv_sec;

int checkname(char *inputname, char *tty);

void mwrite(char *inputname, char *tty);

int main(int argc, char *argv[]) {

  if (argv[1]) {
    if (argv[2]) {
      if(checkname(argv[1],argv[2])) {
        mwrite(argv[1], argv[2]);         
      }
    }
  }
}
//                write(4, "\n",1);
//                printf("Message from %s@%s on %s at %s ...\n", thename, "HOST", tyname, "TIME");
//
   //             while(read(0, &one, 1)) {
    //              write(4, &one, 1);
     //           }

void mwrite(char *inputname, char *tty) {
  struct utmp my_utmp;
  open("/var/run/utmp", 0);
  char *tyname = ttyname(0); 
  char *name;
  while(read(3, &my_utmp, sizeof(struct utmp))) {
    if (my_utmp.ut_type == 7) {
      if(!mstrcmp(my_utmp.ut_line, tyname+5)) {
   //     printf("%d\n", atoi((my_utmp.ut_id)+3));
  //      printf("\n%s\n", my_utmp.ut_id+4);
        name = my_utmp.ut_user;
  //    getpwuid(my_utmp.ut_id)->pw_name;//my_utmp.ut_user;
      }
    }
  }
  close(3);
  open(tty,2);
  write(3, "\nMessage from ",14);
  write(3, name, sizeof(name));
  write(3, "@", 1);
  //printf("Message from %s", name);
  char host[32];
  int h = gethostname(host, sizeof(host));
  write(3, host, sizeof(host));

  long timer = time(NULL);
  char *times = ctime(&timer)+11;
  write(3, " on ", 4);
  write(3, tyname+5, sizeof(tyname));
  write(3, " at ", 4);
  write(3, times, 5);
  write(3, " ... \n", 6);
//  printf("%c%s on %s at %.5s ...\n",'@', host, tyname, (ctime(&timer)+11));
}


int checkname(char *inputname, char *tty){
  struct utmp my_utmp;
  open("/var/run/utmp",0);
  int ret, usercheck, ttycheck;
  ret = usercheck = ttycheck = 0;
  while(read(3,&my_utmp,sizeof(struct utmp))) {
    if(my_utmp.ut_type == 7) {
      char *username = my_utmp.ut_user;
      if(!mstrcmp(username,inputname)) {
        usercheck = 1;
        if (!mstrcmp(my_utmp.ut_line, tty+5)) {
          ret = 1;
          ttycheck = 1;
        } 
      } 
    }
  }
  close(3);
  if (!usercheck) {
    printf("user %s is not logged in", inputname);
  } else if (!ttycheck) {
    printf("user %s is not logged in on %s", inputname, tty);
  }
  return ret;
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
