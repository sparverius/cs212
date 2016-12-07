/* client2.c
 * Caesar client: inet domain
 */

#include <sys/socket.h>
#include <sys/types.h>
#include <sys/un.h>
#include <stdio.h>
#include <stdlib.h>

#include <netinet/in.h>
#include <arpa/inet.h>

int main(void) {

  int socket_fd;

  struct sockaddr_in address; // note un --> in change
  address.sin_family = AF_INET;
  address.sin_addr.s_addr = inet_addr("127.0.0.1");
  //address.sin_port = 9742;
  address.sin_port = htons(9742);

  int len = sizeof(address);
  while(1) {
    char message[23];
    memset(message,0,23);
    socket_fd = socket(AF_INET, SOCK_STREAM, 0); //UNIX -> INET
    int result = connect(socket_fd, (struct sockaddr*)&address, len);

    printf("message to send: "); fflush(stdout);
    int num_r = read(0, &message, 22);
    write(socket_fd, &message, num_r);
    if (strcmp(message, "shutdown\n") == 0) {
      printf("client shutting down\n"); fflush(stdout);
      shutdown(socket_fd, SHUT_RDWR);
      close(socket_fd);
      exit(0);
    }
    read(socket_fd, &message, num_r);
    printf("server replies with: %s\n", message);
    close(socket_fd);
  }
  return 0;
}
