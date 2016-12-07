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
char* itoa(int num, char* str);

char buffer;
void getfrom(char *name);
int word;

int main(int argc, char* argv[]) {
  l_count = m_count = c_count = word = 0;
  int opt;
  char n[10];
  
  char m[10];
  getfrom(argv[argc-1]);
  if (argc > 2) {
    while ((opt = getopt(argc, argv, "cmwl")) != -1) {
    switch(opt) {
      case 'c':
        write(1, itoa(c_count, n), sizeof(n)/4);
        break;
      case 'm': 
       write(1, itoa(m_count, m), sizeof(m)/4);
        break;
      case 'l':
       write(1, itoa(l_count, n), sizeof(n)/4);
        break;
      case 'w':
        //printf("%d ", w_count);
        write(1, itoa(w_count, n), sizeof(n)/4);
        break;
      default: printf("%s", "wrong");
      }
    }
  } else {
    // printf("%2d %2d %2d", l_count, w_count, c_count);
     write(1, itoa(l_count, n), sizeof(n)/4);
     write(1, itoa(w_count, n), sizeof(n)/4);
     write(1, itoa(c_count, n), sizeof(n)/4);
  }
  printf(" %s\n", argv[argc-1]);
}

void getfrom(char *point) {
  open(point, 0);
  while(read(3, &buffer, 1)) {
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

char* itoa(int num, char* str) {
  int i = 0;
  while (num != 0) {
    str[i] = num %10 + 48;
    num /= 10;
    i++;
  }
  str[i++] = '\0';
  char *s1 = str;
  char *s2 = s1 + i-2;
  while (s1 < s2) {//s1 < s2; s1++, s2--) {
    char temp = *s1;
    *s1 = *s2;
    *s2 = temp;
    s1++; s2--;
  }
  return str;
}












