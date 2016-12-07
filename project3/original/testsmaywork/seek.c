//#include <unistd.h>

_FILE_OFFSET_BITS == 64

//typedef long off_t;

//off_t lseek(int fd, off_t offset, int whence);

int main() {
  //signed long a = -10;
  char buff;
  open("one", 0);
  lseek(3,-10, 2);
  while(read(3, &buff, 1)) {
    write(1, &buff, 1);
  }
}
