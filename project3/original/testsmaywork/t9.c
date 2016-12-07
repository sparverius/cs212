//#include <unistd.h>
long lseek(int fd, long offset, int whence);

int main() {
  //signed long a = -10;
  char buff;
  open("one", 0);
  lseek(3,-10, 2);
  while(read(3, &buff, 1)) {
    write(1, &buff, 1);
  }
}
