/* server2.c
 * inet domain Ceasar server
 */

#include <sys/socket.h>
#include <sys/types.h>
#include <sys/un.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <stdlib.h>

#include <netinet/in.h>
#include <arpa/inet.h>

int main(void) {
  int server_sockfd;
  int client_sockfd;

  struct sockaddr_in server_address;
  struct sockaddr_in client_address;

  int server_len = sizeof(server_address);
  int client_len = sizeof(client_address);

  server_address.sin_family = AF_INET;
  server_address.sin_addr.s_addr = inet_addr("127.0.0.1");
  //server_address.sin_addr.s_addr = INADDR_ANY;
  //server_address.sin_addr.s_addr = htonl(INADDR_ANY);
  server_address.sin_port = htons(9742);

  server_sockfd = socket(AF_INET, SOCK_STREAM, 0);

  bind(server_sockfd, (struct sockaddr*)&server_address, server_len);

  listen(server_sockfd, 5);
  printf("\nserver started");
  while(1) {
    char message[23];
    memset(message, 0, 23);
    int client_len = sizeof(client_address);
    client_sockfd =
      accept( server_sockfd,(struct sockaddr*) &client_address, &client_len);

    int num_r = read(client_sockfd, &message, 22);
    int letter;
    int length = strlen(message);
    if (strcmp(message, "shutdown\n") == 0) {
      printf("server shutting down\n");
      shutdown(client_sockfd, SHUT_RDWR);
      close(client_sockfd);
      shutdown(server_sockfd, SHUT_RDWR);
      close(server_sockfd);
      exit(0);
    }
    for(letter = 0; letter < length; letter++) {
      if (message[letter] != 'z')
	message[letter]++;
      else
	message[letter] = 'a';
    }
    write(client_sockfd, &message, length);
    printf("message sent: %s\n", message); fflush(stdout);
    close(client_sockfd);
  }
}
