/* mwc.c
 * Richard Kent
 * Mimicks the wc program.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int getopt(int argc, char * const argv[], const char *optstring);
int c_count, m_count, l_count, w_count;

//char* itoa(int value, char * str, int base);

char buffer;

int main(int argc, char* argv[]) {
 int opt; 
  while ((opt = getopt(argc, argv, "c:m:w:l")) != -1) {
    switch(opt) {
      case 'c':
          open(argv[2], 0);// write(1, "works\n", 6);
          c_count = lseek(3, 0, 2);
          printf("%d\n", c_count);
        break;
      case 'm': 
        open(argv[2], 0);
        while(read(3, &buffer, 1)) {
          if (buffer >= 0 || buffer == -128) {// && buffer >=0) {
            m_count++;
          }
        }
        printf("%d\n", m_count);
        break;
      case 'w':
        open(argv[2], 0);
        while (read(3, &buffer, 1)) {
          if (buffer >= 33){//== '\n') {// || buffer == '\x20') {
            w_count++;
          }
        }
        w_count--;
        printf("%d\n", w_count); 
        break;
      case 'l':
        open(argv[2], 0);
        while(read(3, &buffer, 1)) {
          if (buffer == '\n') {
            l_count++;
          }
        }
        printf("%d\n", l_count);
        break;
      default: write(1, "\n", 10);
    }
  }
}


