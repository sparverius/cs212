/* fileinfo.c
 * Richard Kent
 * Takes a filename as an argument and returns the -l flag representation of ls
 */

#include <sys/stat.h>

int printf(const char *format, ...);
int stat(const char *pathname, struct stat *buf);
char *ctime(const time_t *timep);

int main(int argc, char *argv[]) {

  struct stat my_stat;

  int result = stat(argv[1], &my_stat);
  printf("mode: %lo (octal)\n", (unsigned long) my_stat.st_mode); 
  printf("user: %ld\n", (long) my_stat.st_uid);
  printf("group: %ld\n", (long) my_stat.st_gid);
  printf("total size: %lld (bytes)\n", (long long) my_stat.st_size); 
  printf("number of hard links: %lld\n", (long long) my_stat.st_nlink);
  printf("time of last modification  : %s", ctime(&my_stat.st_mtime));
  printf("time of last access        : %s", ctime(&my_stat.st_atime));
  printf("time of last status change : %s", ctime(&my_stat.st_ctime));

  printf("%12.12s\n", ctime(&my_stat.st_ctime)+4);
}
