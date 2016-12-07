/* mls0.c
 * Richard Kent
 *
 */



#include <dirent.h>
#include <sys/types.h>
#include <stdio.h>

DIR *opendir(const char* name);
struct dirent* reddir(DIR* dirp);

//#define NULL ((void *)0)

//char d_name[256];
char *d_name;

int main(void) {
  DIR *dp;
  struct dirent *ep;
  dp = opendir(".");
  char *name;
  while((ep = readdir(dp)) != NULL) {
    name = (*ep).d_name;
    write(1, name, strlen(name));
    write(1, "\n", 1);
  }
}
