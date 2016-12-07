/* mls0.c
 * Richard Kent
 *
 */
#include <dirent.h>
#include <sys/types.h>
#include <stdio.h>
#include <sys/stat.h>

DIR *opendir(const char* name);
struct dirent* reddir(DIR* dirp);

int stat(const char *pathname, struct stat *buf);
//#define NULL ((void *)0)
//char d_name[256];
char *d_name;
mode_t st_mode;
off_t st_size;

int main(void) {
  DIR *dp;
  struct dirent *ep;

  struct stat *stat_p;

  dp = opendir(".");
  char *name;
  while((ep = readdir(dp)) != NULL) {
    name = (*ep).d_name;
    stat(name, stat_p);
    mode_t one = stat_p->st_size;
    write(1, one, sizeof(one));
    write(1, name, sizeof(name));
    write(1, "\n", 1);
  }
}
