/* pwd0.c
 * Richard Kent
 * Prints the current directories name
 */

#include <dirent.h>

#define NULL (void *)0

int printf(const char *format, ...);
int chdir(const char *path);

DIR *opendir(const char* name);
struct dirent *readdir(DIR* dirp);


char *d_name;

int main(void) {

  DIR *wd;
  struct dirent *ent;
  wd = opendir(".");
  
  unsigned long child; 

  while ((ent = readdir(wd)) != NULL) {
    char *name = ent->d_name;
    if (name[0] == '.' && name[1] == '\0') {
      child = ent->d_ino; 
      printf("%lu\n", child);
    } 
 //   printf("%lu  %s\n", ent->d_ino, name);
  }

  wd = opendir("..");
  while((ent = readdir(wd)) != NULL) {
    if (ent->d_ino == child) {
      char *name = ent->d_name;
      printf("%s\n", name);
    }
  }
  

}
