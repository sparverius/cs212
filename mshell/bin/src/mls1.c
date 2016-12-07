/* mls0.c
 * Richard Kent
 */

#include <dirent.h>
#include <sys/stat.h>
#define NULL ((void *)0)

int write(int fd, const void *buf, int count);
int stat(const char *pathname, struct stat *buf);
int strlength(const char * str);
int getopt(int argc, char* const argv[], const char *optstring);

DIR *opendir(const char* name);
struct dirent* reddir(DIR* dirp);

char *d_name;

int main(int argc, char* argv[]) {
  DIR *dp;
  struct dirent *ep;
  struct stat *stat_p;
  int opt;
  while ((opt = getopt(argc, argv, "l")) != -1) {
    case 'l': 
      if (argv[2]) {
        dp = opendir(argv[2]);
      } else {
        dp = opendir(".");
      }

      break;
    default: dp =  
  }
  if (argv[1]) {
    dp = opendir(argv[1]); 
  } else {
    dp = opendir(".");
  }
  dp = opendir();
  char *name;
  while((ep = readdir(dp)) != NULL) {
    name = ep->d_name;
    stat(name, stat_p);
    write(1, name, strlength(name));
    write(1, "\n", 1);
  }

}

void rddir() {
  DIR *dp;
  struct dirent *ep;
  struct stat *stat_p;

  dp = opendir(".");

}

int strlength(const char * str) {
  int len;
  for (len = 0; str[len]; len++);
  return len;
}


