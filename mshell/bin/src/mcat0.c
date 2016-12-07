/* mcat0.c
 * Richard Kent
 */
int open(const char *pathname, int flags);
int read(int fd, void *buf, int count);
int write(int fd, const void *buf, int count);
int close(int fd);

char buffer;
void cat();

int main(int argc, char *argv[]) {
  if (argv[1]) {
    open(argv[1], 2);
    cat();
  }
  if (argv[2]) {
    open(argv[2], 2);
 	  cat();
  }
  return 0;
}

void cat() {
	while(read(3,&buffer, 1)) {
	  write(1, &buffer, 1);
	}
  close(3);
}
