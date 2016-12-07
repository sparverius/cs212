/* mls0.c
 * Richard Kent
 */

#include <dirent.h>
#include <sys/stat.h>
#define NULL ((void *)0)

int write(int fd, const void *buf, int count);
int stat(const char *pathname, struct stat *buf);

int mstrcmp(const char *one, const char *two);
int strlength(const char * str);

DIR *opendir(const char* name);
struct dirent* reddir(DIR* dirp);

char *d_name;

int main(void) {
  DIR *dp;
  struct dirent *ep;
  struct stat *stat_p;
  int entry_count = 0;

  dp = opendir(".");
  char *name;
  while((ep = readdir(dp)) != NULL) {
    if (mstrcmp(ep->d_name, ".") == 0 || mstrcmp(ep->d_name, "..") == 0 || ep->d_name[0] == '.')
      continue;
    else {
      entry_count++;
    }
    name = ep->d_name;
    stat(name, stat_p);
    write(1, name , strlength(name));
    if (entry_count%7)
      write(1, "  ", 3);
    else
      write(1, "\n", 2);
  }
  if (entry_count%7)
    write(1, "\n", 1);

}

int mstrcmp(const char *one, const char *two) {
  int ret;
  while(!(ret = *(unsigned char *) one - *(unsigned char *)two) && *two)
    ++one, ++two;
  if (ret < 0)
    ret = -1;
  else if (ret > 0)
    ret = 1;
  return ret;
}

int strlength(const char * str) {
  int len;
  for (len = 0; str[len]; len++);
  return len;
}
