/* mhead1.c
 * Richard Kent
 * An example of the head command using system calls.
 */

#define TRUE 1
#define FALSE 0
#define DEFAULT "10"
#define SEEK_END 2

char buffer;
int bytesOrLines;

int findByte(int option);
void reg();
void set(int option, char* whichToOpen, char* byteLines);

int main(int argc, char* argv[]) {
//  switch(argc) {
//    case 2: 
      set(TRUE, argv[1], DEFAULT); //break;
//    case 4:
//      if (argv[1][0] == '-') {
//        switch(argv[1][1]) {
//          case 'c':
//            set(FALSE, argv[3], argv[2]); break;
//          case 'n':
//            set(TRUE, argv[3], argv[2]); break;
//          default: break;
//        }
//      }
//      break;        
//    default: write(1, "\r", 1);
//  }
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


int findByte(int option) {
  int seek = lseek(3, 0, SEEK_END);
  int seekKeep = seek;
  while (bytesOrLines > -1) {
    lseek(3, seek, 0);
    read(3, &buffer, 1);
    if (buffer == '\n') {
      bytesOrLines--;
    }
      seek --;
    if (bytesOrLines == -1) {
      seek += 2;
    }
  }
  return seek;
}

void reg() {
  while (seek < seekKeep) {
    lseek(3, seek, 0);
    read(3, &buffer, 1); 
    write(1, &buffer, 1);
    seek++;
  }
}
