#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>


int main(void) {
    // 1. Create a socket with the socket() system call
    int sock = socket(AF_INET, SOCK_STREAM, 0);

    // 2. Bind the socket to an address using the bind() system call.
    struct sockaddr_in serv_addr = {0};
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(1234);
    bind(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    
    // 3. Listen for connections with the listen() system call
    listen(sock, 128);

    // 4. Accept a connection with the accept() system call.
    struct sockaddr_in cli_addr = {0};
    socklen_t cli_addrlen = sizeof(cli_addr);
    int acc_sock = accept(sock, (struct sockaddr *)&cli_addr, &cli_addrlen);


int check = 1;
    while (check==1)
{

    // 5. Send and receive data
    char buf[1024];
    ssize_t nread;

    // Read from socket, write to stdout
    nread = read(acc_sock, buf, 1024);
    int cmp = strcmp(buf , "out");
    if (cmp == 10)
    {
        check = 0;
    }
    write(1, buf, nread);
}
}
