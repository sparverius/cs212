/* pwd0.c
 * Richard Kent
 * Prints the current directories name
 */

#include <dirent.h>
#include <string.h>

int printf(const char *format, ...);
int chdir(const char *path);
//DIR *opendir(const char* name);
//struct dirent *readdir(DIR* dirp);

char *d_name;
DIR *wd;
struct dirent *ent;

void printpath();
unsigned long get_ino(char *dir);
char* printname(unsigned long ino);

int main(void) {
  printpath();
  write(1,"\b",1);
  write(1,"\b",1);
  printf("%c",'\n');
}

void printpath() {
  char *dname;
  if (get_ino(".") == get_ino("..")) {
    printf("/");
    return;
  }
  dname = printname(get_ino("."));
  printpath();
  printf("%s%s",dname, "/");  
}

unsigned long get_ino(char *dir) {
  wd = opendir(dir);
  unsigned long child = -1;
  while((ent = readdir(wd)) != NULL) {
    char *name = ent->d_name;
    if (strcmp(name, ".") == 0) {
      child = ent->d_ino;
      return child;
    }
 }
  return child;
}

char* printname(unsigned long ino) {
  chdir("..");
  wd = opendir(".");
  char *pname;
  while((ent = readdir(wd)) != NULL) {
    if (ent->d_ino == ino) {
      pname = ent->d_name;
    }
  }
  return pname;
}
