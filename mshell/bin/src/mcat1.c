/* mcat1.c
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
  write(1,"*", 1);
	while(read(3,&buffer, 1)) {
	  write(1, &buffer, 1);
    if (buffer == '\n') {
			write(1,"*", 1);
		}
    
	}
	if (!read(3,&buffer,1)) {
			write(1,"\b",1);
	}
  close(3);
}
