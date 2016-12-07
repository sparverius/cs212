
//typedef int bool;
#define TRUE 1
#define FALSE 0
#define LINES 10

int atoi(const char *nptr);

char buffer;
int bytesOrLines;

void reg();


int main(int argc, char* argv[]) {

   if (argv[2]) {
      open(argv[3], 0);
      bytesOrLines = atoi(argv[2]);
      reg(FALSE);
   } else {
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
