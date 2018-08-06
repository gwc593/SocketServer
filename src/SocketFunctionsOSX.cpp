//
// Created by Guy Collins on 06/08/2018.
//

#include <SocketFunctionsOSX.hpp>


void welcome_message()
{
    printf("this is working now...\n");
}

// Author: Guy Collins
// Date: 06/08/2018
// Description: function to set up a handle to a new socket for listening.
int creatSocketServer(int PORT)
{
    int server_fd, new_socket, valread;

    struct sockaddr_in address;
    int addrlen = sizeof(address);
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( PORT );


    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    return server_fd;
}

void ServerSocket::setPort(int port)
{
    PORT = port;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( PORT );
}

int ServerSocket::init()
{
    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("socket failed:");
        exit(EXIT_FAILURE);
    }


    // Forcefully attaching socket to the port 8080
    if (bind(server_fd, (struct sockaddr *)&address,
             sizeof(address))<0)
    {
        perror("bind fail:");
        exit(EXIT_FAILURE);
    }
    if (listen(server_fd, 3) < 0)
    {
        perror("listen error:");
        exit(EXIT_FAILURE);
    }

    if ((socketHandle = accept(server_fd, (struct sockaddr *)&address,
                             (socklen_t*)&addrlen))<0)
    {
        perror("accept error:");
        exit(EXIT_FAILURE);
    }

    return socketHandle;
}

void ServerSocket::passiveRead(char *buffer, int buffLen)
{
    read(socketHandle,buffer,buffLen);
}

void ServerSocket::activeSend(char *buffer, int buffLen)
{
    send(socketHandle,buffer,buffLen,0);
}