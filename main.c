#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "command.h"
#include <sys/socket.h>
#include <netinet/in.h>


int main(int argc , char const *argv[]){
    int state = 1;
    int sock; 
    int output;
    output = dup(STDOUT_FILENO);
    while (state)
    {
        char path[100];
        char command[200];
        printf("%s ?> ",getcwd(path,100));
        scanf("%[^\n]%*c",command);
        // exit command 
        if (strcmp(&command,"exit")==0){
            state=0;
            printf("bye..\n");
        }
        // echo command
        else if (strcmp(firstWord(command , 4),"echo") == 0){
            getTheEcho(command);
        }
        // dir command
        else if (strcmp(firstWord(command , 3),"dir") == 0 && strlen(command)==3){
            getListDir(path);
        }
        // cd command
        else if (strcmp(firstWord(command , 2),"cd") == 0 && strlen(command)>3){
            changeDir(command);
        }
        // tcp port
        else if (strcmp(firstWord(command , 8),"tcp port") == 0 && strlen(command)==8)
        {
        sock = socket(AF_INET, SOCK_STREAM, 0);
        struct sockaddr_in serv_addr = {0};
        serv_addr.sin_family = AF_INET;
        serv_addr.sin_port = htons(1234);
        serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
        connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
        dup2(sock, STDOUT_FILENO);
        execl("matla1/shell" , "shell" , NULL);
        }
        // stop the client & server sockets
        else if (strcmp(firstWord(command , 5),"local") == 0 && strlen(command)==5)
        {
            system("echo local");
            dup2(output,STDOUT_FILENO);
            
            close(output);
            int c_s = close(sock);
            if (c_s != 0)
            {
                perror("there is no socket opened");
            }
            
        }
        else
        {
            system(command);
        }
        
        
        
    }
    return 0 ;
}

