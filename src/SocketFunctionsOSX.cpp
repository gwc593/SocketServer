//
// Created by Guy Collins on 06/08/2018.
//

#include <SocketFunctionsOSX.hpp>



// Author: Guy Collins
// Date: 06/08/2018
//Class: ServerSocket
// Description: Object orientated socket wrapper.

void ServerSocket::setPort(int port)
{
    _PORT = port;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( _PORT );
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


void ClientSocket::setPort(int port)
{
    _PORT = port;
}

void ClientSocket::setIP(char* ip)
{
    strcpy(_ip,ip);
}

void ClientSocket::setup(char* ip, int port)
{
    _PORT = port;
    strcpy(_ip,ip);
}

int ClientSocket::init()
{
    if ((socketHandle = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("\n Socket creation error \n");
        return -1;
    }

    memset(&serv_addr, '0', sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(_PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0)
    {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }

    if (connect(socketHandle, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("\nConnection Failed \n");
        return -1;
    }
}

void ClientSocket::activeSend(char *buffer, int buffLen)
{
    send(socketHandle,buffer,buffLen,0);
}

void ClientSocket::passiveRead(char *buffer, int buffLen)
{
    read(socketHandle,buffer,buffLen);
}