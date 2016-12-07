/* mhead1.c
 * Richard Kent
 * An example of the head command using system calls.
 */


//typedef int bool;
#define TRUE 1
#define FALSE 0
#define LINES 10

char buffer;
int bytesOrLines;
void reg(int option);

int main(int argc, char* argv[]) {
  if (!argv[1]) {
    write(1,"\r",1);
  }
  else if (argv[2]) {
      bytesOrLines = atoi(argv[2]);
      open(argv[3], 0);
      if (argv[1][1] == 'c') {
        reg(FALSE);
      } else {
        reg(TRUE);
      }
   } 
   else {//if(argv[1]){
      bytesOrLines = LINES;
      open(argv[1], 0);
      reg(TRUE);
    }
  return 0;
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
