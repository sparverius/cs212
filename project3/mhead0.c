/* mhead0.c
 * Richard Kent
 */

#define LINES 10

int main(int argc, char* argv[]) {

  int lines = LINES;
  char buffer;
  if (argc > 1) {
    open(argv[1], 0);
    while (lines > 0) {
      read(3, &buffer, 1);
      write(1, &buffer, 1);
      if (buffer == '\n')
        lines--;
    }
  }
  return 0;
}

