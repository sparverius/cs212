/* mwrite2.c
 * Richard Kent
 * Checks if the target user is logged in at specified terminal.
 */
#include <utmp.h>
#include <unistd.h>
#include <time.h>

int printf(const char *format, ...);
int open(const char *pathname, int flags);
int gethostname(char *name, size_t len);
int strcmp(const char *s1, const char *s2);
struct passwd *getpwuid(uid_t uid);

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

void mwrite(char *inputname, char *tty) {
  struct utmp my_utmp;
  open("/var/run/utmp", 0);
  char *tyname = ttyname(0); 
  char *name;
  while(read(3, &my_utmp, sizeof(struct utmp))) {
    if (my_utmp.ut_type == 7 && !strcmp(my_utmp.ut_line, tyname+5)) {
        name = my_utmp.ut_user;
    }
  }
  close(3);
  open(tty,2);
  write(3, "\nMessage from ",14);
  write(3, name, sizeof(name));
  write(3, "@", 1);
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
  char buffer;
  while(read(0, &buffer, 1)) {
    write(3, &buffer, 1);
  }
}


int checkname(char *inputname, char *tty){
  struct utmp my_utmp;
  open("/var/run/utmp",0);
  int ret, usercheck, ttycheck;
  ret = usercheck = ttycheck = 0;
  while(read(3,&my_utmp,sizeof(struct utmp))) {
    if(my_utmp.ut_type == 7 && !strcmp(my_utmp.ut_user,inputname)) {
        usercheck = 1;
        if (!strcmp(my_utmp.ut_line, tty+5)) {
          ret = 1;
          ttycheck = 1;
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

