/*  server.c
 *  next letter server: provides next (lowercase) letter in alphabet to client
 *  unix domain
 */

#include <sys/socket.h>
#include <sys/types.h>
#include <sys/un.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(void) {

    int server_sockfd; 
    int client_sockfd;

    struct sockaddr_un server_address;
    struct sockaddr_un client_address;

    int server_len = sizeof(server_address);
    int client_len = sizeof(client_address);

    server_address.sun_family = AF_UNIX;
    strcpy(server_address.sun_path,"just_letters");
    
    unlink("server_socket");

    server_sockfd = socket(AF_UNIX, SOCK_STREAM, 0);

    bind(server_sockfd, 
         (struct sockaddr*) &server_address, server_len);

    listen(server_sockfd,5);
    printf("\nserver started\n");
    while(1) {
       char letter = 'A';
       
       int client_len = sizeof(client_address);
       client_sockfd = 
               accept( server_sockfd, 
                       (struct sockaddr*) &client_address, &client_len);

       read(client_sockfd, &letter,1);
       if (letter != 'z')
          letter++;
       else
          letter = 'a';
       write(client_sockfd, &letter,1);
       printf("\nletter sent: %c\n", letter); fflush(stdout);
       close(client_sockfd);
    }
}
