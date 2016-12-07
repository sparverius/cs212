/* mwrite2.c
 * Richard Kent
 * Checks if the target user is logged in at specified terminal.
 */
#include <utmp.h>
#include <unistd.h>
#include <time.h>

int dprintf(int fd, const char *format, ...);
int printf(const char *format, ...);
int open(const char *pathname, int flags);
int gethostname(char *name, size_t len);
int strcmp(const char *s1, const char *s2);
struct passwd *getpwuid(uid_t uid);

int checkname(char *inputname, char *tty);
void mwrite(char *tty);
char *get_username(char *a_tty);
struct utmp my_utmp;

int main(int argc, char *argv[]) {
  char *get_username();
  if (argv[1]) {
    if (argv[2]) {
      if(checkname(argv[1],argv[2])) {
        mwrite(argv[2]);         
      }
    }
  } else {
    printf("usage: mwrite user [tty]");
  }
}

void mwrite(char *tty) {
  char *tyname = ttyname(0); 
  char *name = get_username(tyname);
  open(tty,2);
  char host[32];
  dprintf(3, "\nMessage from %s@",name);
  int h = gethostname(host, sizeof(host));
  long timer = time(NULL);
  char *times = ctime(&timer)+11;
  dprintf(3, "%s on %s at %.5s ...\n", host, tyname+5, times);
  char buff;
  while(read(0, &buff, 1)) {
    write(3, &buff, 1);
  }
}


int checkname(char *inputname, char *tty){
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
    printf("user %s is not logged in\n", inputname);
  } else if (!ttycheck) {
    printf("user %s is not logged in on %s\n", inputname, tty);
  }
  return ret;
}

char *get_username(char *a_tty) {
  open("/var/run/utmp", 0);
  char *ret;
  while (read(3, &my_utmp, sizeof(struct utmp))) {
    if (!strcmp(my_utmp.ut_line, a_tty+5)) {
      ret = my_utmp.ut_user; 
      break;
    }
  }
  close(3);
  return ret;
}
