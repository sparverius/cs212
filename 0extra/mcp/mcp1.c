int open(const char* pathname, int flags, ...);
int write(int fd, const void *buf, int count);
int read(int fd, void *buf, int count);


#define O_RDONLY 0
#define O_WRONLY 1
#define O_CREAT 0100

char buffer;

int main(int argc, char *argv[]) {
  open(argv[1], O_RDONLY);
  open(argv[2], (O_WRONLY | O_CREAT), 0600);
  while (read(3, &buffer,1)) {
    write(4, &buffer, 1);
  }
}
