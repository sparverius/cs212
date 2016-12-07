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

char *checkname(char *tty);
void mwrite(char *tty);
struct utmp my_utmp;

int main(int argc, char *argv[]) {
  if (argv[1]) {
    if (!checkname(argv[1]))
      printf("user %s is not logged in\n", argv[1]); 
    if (argv[2]) {
      if (checkname(argv[2]) && !strcmp(checkname(argv[2]), argv[1]))
        mwrite(argv[2]);         
      else 
        printf("user %s is not logged in on %s\n", argv[1], argv[2]);
    }
  } else {
    printf("usage: mwrite user [tty]");
  }
}

char* checkname(char *tty){
  open("/var/run/utmp",0);
  char *ret = NULL;
  while(read(3,&my_utmp,sizeof(struct utmp))) {
    if (!strcmp(my_utmp.ut_user, tty)) {        //checks if argv[1] is a logged in user 
      ret = my_utmp.ut_user; break;               // returns username if true otherwise returns NULL
    }
    else if (!strcmp(my_utmp.ut_line, tty+5)) {
      ret = my_utmp.ut_user; break;
    }
  }
  close(3);
  return ret;
}

void mwrite(char *tty) {
  char *name = checkname(ttyname(0));
  long timer = time(NULL);
  char *times = ctime(&timer)+11;
  char host[32];
  open(tty,2);
  dprintf(3, "\nMessage from %s@",name);
  int h = gethostname(host, sizeof(host));
  dprintf(3, "%s on %s at %.5s ...\n", host, ttyname(0)+5, times);
  char buff;
  while(read(0, &buff, 1)) {
    write(3, &buff, 1);
  }
}
