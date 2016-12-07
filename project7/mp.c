/* pwd0.c
 * Richard Kent
 * Prints the current directories name
 */

#include <dirent.h>
#include <string.h>

//#define NULL (void *)0

int printf(const char *format, ...);
int chdir(const char *path);

DIR *opendir(const char* name);
struct dirent *readdir(DIR* dirp);

unsigned long get_ino(char *dir);

char *d_name;
DIR *wd;
struct dirent *ent;

void printpath();
unsigned long get_ino(char *dir);
void printname(unsigned long ino);


int main(void) {
//  printf("%lu", get_ino(".")); 
  printpath();
}

void printpath() {
  if (get_ino(".") == get_ino("..")) {
    printf("/\n");
    printf("%lu\n", get_ino("."));
    printf("%lu\n", get_ino(".."));
    return;
  }
//    printpath();
    printname(get_ino("."));
  chdir("..");
   
}

unsigned long get_ino(char *dir) {
  wd = opendir(dir);
  unsigned long child = -1;
  while((ent = readdir(wd)) != NULL) {
    char *name = ent->d_name;
    if (strcmp(name, ".") == 0) {
      child = ent->d_ino;
      return child;
//    if (name[0] == '.' && name[1] == '\0') {
//      child = ent->d_ino;
    }
 }
  return child;
}

void printname(unsigned long ino) {
//  chdir("..");
  while((ent = readdir(wd)) != NULL) {
    if (ent->d_ino == ino) {
      char *pname = ent->d_name;
      printf("%s", pname);
    }
  }
}
