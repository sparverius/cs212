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


void getnum();
void pr();

char *d_name;
int name_longest;

int main(void) {
  getnum();
  pr();
}
void getnum() {
  DIR *dp;
  struct dirent *ep;
  struct stat *stat_p;
  int entry_count = 0;
  dp = opendir(".");
  char *name;
  int temp = 0;
  while((ep = readdir(dp)) != NULL) {
    name = ep->d_name;
    stat(name, stat_p);
    if (mstrcmp(ep->d_name, ".") != 0 && mstrcmp(ep->d_name, "..") != 0 && ep->d_name[0] != '.') { 
       temp = strlength(name); 
       if (temp > name_longest)
         name_longest = temp + 2;
    }
  }
}

void pr() {
  DIR *dp;
  struct dirent *ep;
  struct stat *stat_p;
  int entry_count = 0;
  dp = opendir(".");
  char *name;
  int temp = 0;
  while((ep = readdir(dp)) != NULL) {
    if (mstrcmp(ep->d_name, ".") == 0 || mstrcmp(ep->d_name, "..") == 0 || ep->d_name[0] == '.')
      continue;
    else 
      entry_count++;
    name = ep->d_name;
    stat(name, stat_p);
    temp = strlength(name);
    write(1, name , strlength(name));
    while ( temp < name_longest) {
      write(1, " ", 1); 
      temp++;
    }
    if (entry_count%10 == 0) {
      write(1, "\n", 1);
    }
  }
  if (entry_count%10 != 0) {
    write(1, "\n", 1);
  } 
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
