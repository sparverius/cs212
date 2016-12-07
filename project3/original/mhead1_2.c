/* mhead1.c
 * Richard Kent
 * An example of the head command using system calls.
 */


//typedef int bool;
#define TRUE 1
#define FALSE 0
#define DEFAULT "10"

char buffer;
int bytesOrLines;
void reg(int option);
void set(int option, char* whichToOpen, char* byteLines);

int main(int argc, char* argv[]) {
  printf("%c", argv[1][2]);

  switch(argc) {
    case 2: set(TRUE, argv[1], DEFAULT); break;
    case 4:
      if (argv[1][1] == 'c') {
        set(FALSE, argv[3], argv[2]);
      }
      if (argv[1][1] == 'n') {
        set(TRUE, argv[3], argv[2]);
      }
      if (argv[2][1] == 'c') {
        set(FALSE, argv[1], argv[3]);
      }
      if (argv[2][1] == 'n') {
        set(TRUE, argv[1], argv[3]);
      }
      break;
    default: write(1, "\r", 1);
  }
  return 0;
}


void set(int option, char* whichToOpen, char* byteLines) {
  open(whichToOpen, 0);
  bytesOrLines = atoi(byteLines);
  if (!option) {
    reg(FALSE);
  } else {
    reg(TRUE);
  }
}


void reg(int option) {
  while (bytesOrLines > 0) {
    read(3, &buffer, 1); 
      write(1, &buffer, 1);
      if (buffer == '\n' && option) {
        bytesOrLines--;
      }
      else if (!option){
        bytesOrLines--;
      }
  }
}
