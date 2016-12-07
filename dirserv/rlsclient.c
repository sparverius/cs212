/* rlsclient.c
 * remote directory listing client
 * simple protocol: client sends single line with name of directory
 *                  server sends back the list of files in that directory
 */

#include <sys/socket.h>
#include <sys/types.h>
#include <sys/un.h>
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char* argv[]) {

  if (argc != 4) {
    printf("Usage: rlsclient IP# port directory\n");
    exit(0);
  }
  char buffer[BUFSIZ];
  int read_count;

  struct sockaddr_in server_address;
  int socket_id;

  server_address.sin_family = AF_INET;
  server_address.sin_addr.s_addr = inet_addr(argv[1]);
  server_address.sin_port = atoi(argv[2]);     // 1. look up phone number
                                               //    (set server location)
  int len = sizeof(server_address);

  socket_id = socket(AF_INET, SOCK_STREAM, 0); // 2. get phone (get socket)

  int result = connect(socket_id, (struct sockaddr*)&server_address, len);
  // 3. dial phone wait for someone to answer (connect to server)

  write(socket_id, argv[3],strlen(argv[3]));   // send over directory name
  write(socket_id, "\n", 1);

  while( (read_count = read(socket_id, buffer, BUFSIZ)) > 0) // get response
    write(1,buffer,read_count);
  close(socket_id);
  return 0;
  
}
