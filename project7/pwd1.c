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

void get_ino(DIR *wd, struct dirent *ent, unsigned long child);

int main(void) {

  DIR *wd;
  struct dirent *ent;
  wd = opendir(".");
  get_ino(wd, ent, 0);  
//  unsigned long child; 

//  get_ino(opendir("."), ent, 0);
//while ((ent = readdir(wd)) != NULL) {
//  char *name = ent->d_name;
//  if (name[0] == '.' && name[1] == '\0') {
//    child = ent->d_ino; 
//    printf("%lu\n", child);
//  } 
 //   printf("%lu  %s\n", ent->d_ino, name);
// }

//  wd = opendir("..");
//while((ent = readdir(wd)) != NULL) {
//  if (ent->d_ino == child) {
//    char *name = ent->d_name;
//    printf("%s\n", name);
//  }
//}
  

}

//void get_ino(DIR *wd, struct dirent *ent, unsigned int child) {
void get_ino(DIR *wd, struct dirent *ent, unsigned long child) {
  char *name; 
//  unsigned long child;
  wd = opendir(".");
  unsigned long child2;
  if (child2 == child) {
    printf("/");
    
  }
  while ((ent = readdir(wd)) != NULL ) {
    if (ent->d_ino == child) {
      printf("%s ", "/");
    }
    name = ent->d_name;
   if (name[0] == '.' && name[1] == '\0') {
      child2 = ent->d_ino; 
     chdir("..");
      
      get_ino(wd, ent, child2);
      //wd = opendir(".");
      //get_ino(wd, ent, child);
    }    
     if (ent->d_ino == child ) {
      printf("%s ", name);
//      chdir("..");
//      get_ino(wd, ent,child2);
    }
    
  }

}

