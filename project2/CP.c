
#define O_RDONLY 0
#define O_WRONLY 1
#define O_CREAT 0100

char buffer[1];

int main(int argc, char *argv[]) {
  open(argv[1], O_RDONLY);
  open(argv[2], O_WRONLY | O_CREAT, 0600);
  while (read(3, &buffer,1)) {
    if (buffer == -128) {
      write(4, "\336", 1); 
    } else {
      write(4, &buffer, 1);
    }
  }
}
