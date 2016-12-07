/* fileinfo.c
 * Richard Kent
 * Takes a filename as an argument and returns the -l flag representation of ls
 */

#include <sys/stat.h>
#include <grp.h>
#include <pwd.h>
#include <dirent.h>

#define NULL (void *)0

int printf(const char *format, ...);
int stat(const char *pathname, struct stat *buf);
char *ctime(const time_t *timep);

DIR *opendir(const char* name);
struct dirent* reddir(DIR* dirp);
char *d_name;

struct group *getgrgid(gid_t gid);
struct passwd *getpwuid(uid_t uid);

int main(int argc, char *argv[]) {
  struct stat my_stat;
  char perm[11] = {'-','r','w','x','r','w','x','r','w','x'};


  DIR *di;
  struct dirent *en;
  di = opendir(".");
  while((en = readdir(di)) != NULL) {
    char *name = en->d_name;
    int result = stat(name, &my_stat);
    //int result = stat(argv[1], &my_stat);
    unsigned long mo = (unsigned long) my_stat.st_mode; 
    char def[11] =  "----------"; 
    unsigned long mask = 1;

    for (int i = 9; i > 0; i--) {
      if(mo&mask) {
       // char a = perm[i];
        def[i] = perm[i];
      }
      mask = mask<<1;
    }
    struct group *gp = getgrgid(my_stat.st_gid); 
    struct passwd *user = getpwuid(my_stat.st_uid);

    printf("%s", def);
    printf(" %lld", (long long) my_stat.st_nlink);
    printf(" %s %s", user->pw_name, gp->gr_name);
    printf(" %*lld",4, (long long) my_stat.st_size);
    printf(" %12.12s", ctime(&my_stat.st_ctime)+4);
    printf(" %s\n", name);
  }
}


