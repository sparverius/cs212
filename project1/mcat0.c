/* mcat0.c
 * Richard Kent
 *
 */

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
