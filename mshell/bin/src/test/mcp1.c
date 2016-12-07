

//int open(const char *pathname, int flags);
int open(const char *pathname, int flags, ...);
int read(int fd, void *buff, int count);
int write(int fd, const void *buff, int count);
int close(int fd);

#define O_RDONLY 0
#define O_WRONLY 1
#define O_CREAT 0100

char buffer[1];

int main(int argc, char *argv[]) {
  open(argv[1], O_RDONLY);
  open(argv[2], O_WRONLY | O_CREAT, 0600);
  while (read(3, &buffer,1)) {
    write(4, &buffer, 1);
  }
  close(3);
  close(4);
}
