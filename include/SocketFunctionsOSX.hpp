//
// Created by Guy Collins on 06/08/2018.
//

#ifndef SOCKET_LISTEN_SOCKETFUNCTIONSOSX_HPP
#define SOCKET_LISTEN_SOCKETFUNCTIONSOSX_HPP

#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include<arpa/inet.h>

#define DEFAULT_PORT 8080
#define  BUFF_SIZE 1024

// Author: Guy Collins
// Date: 06/08/2018
// Description: Object orientated socket server wrapper.
class ServerSocket
{
private:
    int server_fd, socketHandle, _PORT;

    struct sockaddr_in address;
    int addrlen = sizeof(address);

public:

    void setPort(int port);

    int init();

    int passiveRead(char* buffer, int buffLen);

    void activeSend(char* buffer, int buffLen);

    void acceptNew();

    void Close();
};

// Author: Guy Collins
// Date: 06/08/2018
// Description: Object orientated socket Client wrapper.
class ClientSocket
{
private:
    int _PORT;
    char _ip[12];

    int socketHandle = 0;
    struct sockaddr_in serv_addr;
    char _buffer[BUFF_SIZE];

public:

    void setPort(int port);

    void setIP(char* ip);

    void setup (char* ip, int port);

    int init();

    int activeSend(char* buffer);

    ssize_t passiveRead(char* buffer, int buffLen);

    void Close();
};



#endif //SOCKET_LISTEN_SOCKETFUNCTIONSOSX_HPP
