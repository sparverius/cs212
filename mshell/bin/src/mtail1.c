/* mhead1.c
 * Richard Kent
 * An example of the head command using system calls.
 */


#define TRUE 1
#define FALSE 0
#define DEFAULT "10"
#define SEEK_END 2

int open(const char *pathname, int flags);
int read(int fd, void *buf, int count);
int write(int fd, const void *buf, int count);
unsigned long lseek(int fd, unsigned long offset, int whence);

void set(int option, char* whichToOpen, char* byteLines);
int findbyte(int option, int seekKeep, int bytesOrLines);

int main(int argc, char* argv[]) {
  switch(argc) {
    case 2: 
      set(TRUE, argv[1], DEFAULT); break;
    case 4:
      if (argv[1][0] == '-') {
        switch(argv[1][1]) {
          case 'c':
            set(FALSE, argv[3], argv[2]); break;
          case 'n':
            set(TRUE, argv[3], argv[2]); break;
          default: break;
        }
      }
      break;        
    default: write(1, "\r", 1);
  }
  return 0;
}

void set(int option, char* whichToOpen, char* byteLines) {
  char buffer;
  open(whichToOpen, 0);
  int seekKeep = lseek(3, 0, SEEK_END);
  int bytesOrLines = atoi(byteLines);

  int seek = findbyte(option, seekKeep, bytesOrLines);
  while (seek < seekKeep) {
    lseek(3, seek++, 0);
    read(3, &buffer, 1);
    write(1, &buffer, 1);
  }
}

int findbyte(int option, int seekKeep, int bytesOrLines) {
  char buffer;
  int seek = seekKeep;
  if(option) {
    bytesOrLines++;
  }
  while (bytesOrLines > 0) {
    read(3, &buffer, 1);
    lseek(3, seek, 0);
    if (option && buffer == '\n') {
      bytesOrLines--;
    }
    if (!option) {
      bytesOrLines--;
    }
    if (seek == 0) {
      bytesOrLines--;
    }
    seek --;
  }
  if (option) {
    return seek + 3;
  } else {
    return seek;
  }
}


