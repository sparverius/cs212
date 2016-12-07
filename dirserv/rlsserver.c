/* rlsserver.c
 * remote directory server
 */

#include <sys/socket.h>
#include <sys/types.h>
#include <sys/un.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <netdb.h>
#include <time.h>
#include <strings.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <ctype.h>


void secure(char* line);

int main(int argc, char* argv[]) {
  if (argc != 3) {
    printf("Usage: rsserver IP#  port\n");
    exit(0);
  }

  int socket_id;
  int socket_fd;
  struct sockaddr_in address;    //server address

  FILE* socket_fpin;
  FILE* socket_fpout;            // use socket as text stream
  FILE* pipe_fp;

  char dirname[BUFSIZ];
  char command[BUFSIZ];
  int dir_length;
  int byte;

  // 1. socket (connect phone to line)
  socket_id = socket(PF_INET, SOCK_STREAM, 0);

  int address_length = sizeof(address);
  address.sin_family = AF_INET;
  address.sin_addr.s_addr = inet_addr(argv[1]);   // IP # of server
  address.sin_port = atoi(argv[2]);               // port of server

  // 2. bind  (get phone number for this phone line)
  bind(socket_id, (struct sockaddr*)&address, address_length);

  listen(socket_id, 1);   // 3. listen (activate phone: rings when called

  while(1) {
    socket_fd = accept( socket_id, NULL, NULL);  // 4. accept (wait by phone)
    write(1, "Got a Call!\n", 12);

    socket_fpin = fdopen(socket_fd, "r");  // open socket as file for reading
    fgets(dirname, BUFSIZ - 5, socket_fpin);

    secure(dirname);  // what does this do?

    socket_fpout = fdopen(socket_fd, "w");  // open socket as file for writing

    sprintf(command, "ls %s", dirname);  // read up on what this does!
    pipe_fp = popen(command, "r");  // what does system call popen do?

    while ( (byte = getc(pipe_fp)) != EOF )
      putc(byte, socket_fpout);

    pclose(pipe_fp);
    fclose(socket_fpout);
    fclose(socket_fpin);
  }

}

void secure(char* line) {
  char* source;
  char* destination;
  source = destination = line;
  for( ; *source > 0; source++)              // source is a pointer
    if (*source == '/' || isalnum(*source))  // check out isalnum
      *destination++ = *source;              // x++ gives value then increments
  *destination = '\0';
}
