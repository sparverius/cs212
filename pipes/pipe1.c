#include <stdio.h>
#include <unistd.h>
#include <string.h>
#define PUFFS 100

int main(void) {
  int peace[2]; // [0] is read out end
                // [1] is write in end;
                //  0  looks like o(ut)
                //  1  looks like i(n)
  char smoke[PUFFS];
  int puffs;

  pipe(peace);
  printf("Made a pipe. Read(out) file descriptor:"
         "%d and Write(in) %d\n", peace[0], peace[1]);

  while (fgets(smoke, PUFFS, stdin)) {
    puffs = strlen(smoke);
    write(peace[1], "puff... ", 8);
    write(peace[1], smoke, puffs -1);
    write(peace[1], "  puff... ", 10);
    write(peace[1], "\n", 1);
    int puff;
    // This loop erases smoke buffer
    for (puff = 0; puff < puffs; puff++)
      smoke[puff] = 'S';
    puffs = read(peace[0], smoke, PUFFS);
    write(1, smoke, puffs);
  }
  return 0;
}
