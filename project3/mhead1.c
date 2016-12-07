/* mhead1.c
 * Richard Kent
 * An example of the head command using system calls.
 */

#define TRUE 1    // lines
#define FALSE 0   // bytes
#define LINES 10

void display(int isLines, int amount);
char buffer;
int amount;


int main(int argc, char* argv[]) {
  if (argc == 1) {
    write(1, "\r", 1);
  }
  else if (argc == 2) {
    open(argv[1], 0);
    amount = LINES;
    display(TRUE, amount);
  }
  else if (argc == 4) {
    amount = atoi(argv[2]);
    open(argv[3], 0);
    if (argv[1][1] == 'c')
      display(FALSE, amount);
    else if (argv[1][1] == 'n')
      display(TRUE, amount);
  } 
  return 0;
}

void display(int isLines, int amount) {
  while (amount > 0) {
    read(3, &buffer, 1);
    write(1, &buffer, 1);  
    if (isLines && (buffer == '\n'))
      amount--; 
    else if (!isLines)
      amount--;
  }
}
