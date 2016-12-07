/* mwc0.c
 * Richard Kent
 * After being provided a file, returns the character count.
 */

#include <unistd.h> //int getopt(int argc, char * const argv[], const char *optstring);
int open(const char *pathname, int flags);
int printf(char *format, ...);

int main(int argc, char *argv[]) {
  int c_count = 0;
  char buffer;
  int opt;
  while( (opt = getopt(argc, argv, "c:")) != -1) {
    open(optarg, 0);
    if (opt == 'c') {
      while(read(3, &buffer, 1)) {
        if(buffer >= 0 && buffer <= 127) {
          c_count++;
        }
      }
      //or//  c_count = lseek(3, 0, 2);
      printf("%d %s\n",c_count,  optarg);
    }
  }
}
