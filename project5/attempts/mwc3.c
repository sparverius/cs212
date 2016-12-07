/* mwc.c
 * Richard Kent
 * Mimicks the wc program.
 */
int open(const char *pathname, int flags);
int write(int fd, const void *buf, int count);
int read(int fd, void *buf, int count);
int printf(const char *format, ...);
int getopt(int argc, char * const argv[], const char *optstring);
int c_count, m_count, l_count, w_count;


char buffer;
void getfrom(char *name);
int word;

void getword(char wd);

int main(int argc, char* argv[]) {
  l_count = m_count = c_count = word = 0;
  int opt;
  getfrom(argv[argc-1]);
  if (argc > 2) {
    while ((opt = getopt(argc, argv, "cmwl")) != -1) {
    switch(opt) {
      case 'c':
          printf("%d ", c_count);
        break;
      case 'm': 
        printf("%d ", m_count);
        break;
      case 'l':
        printf("%d ", l_count);
        break;
      case 'w':
        printf("%d ", w_count);
        break;
      default: printf("%s", "wrong");
      }
    }
  } else {
     printf("%2d %2d %2d", l_count, w_count, c_count);

  }
  printf(" %s\n", argv[argc-1]);
}

void getfrom(char *point) {
 
  open(point, 0);
  while(read(3, &buffer, 1)) {
    //getword(buffer);
    if(buffer >=0) {
      c_count++;
      m_count++;
      if (buffer == '\n') {
        l_count++;
      }
    }
    if(buffer == ' ' || buffer == '\n') {
      word = 0;
    } else if (word == 0) {
      w_count++;
      word = 1;
    }
  }
}

void getword(char wd) {
  if (wd == ' ') {
    word = 0;
  } else if (wd == 0) {
    w_count++;
    word = 1;
  }

}


