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

void welcome_message();


// Author: Guy Collins
// Date: 06/08/2018
// Description: function to set up a handle to a new socket for listening.
int creatSocketServer(int PORT);


class ServerSocket
{
    private:
    int server_fd, socketHandle, PORT;

    struct sockaddr_in address;
    int addrlen = sizeof(address);

    public:

    void setPort(int port);

    int init();

    void passiveRead(char* buffer, int buffLen);

    void activeSend(char* buffer, int buffLen);
};


#endif //SOCKET_LISTEN_SOCKETFUNCTIONSOSX_HPP
