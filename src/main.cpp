// Server side C/C++ program to demonstrate Socket programming

#ifdef __APPLE__
#include<SocketFunctionsOSX.hpp>
#else
#include<SocketFunctionsOSX.hpp>
#endif



#define DEFAULT_PORT 8080
#define  BUFF_SIZE 1024
int main(int argc, char const *argv[])
{
    //declarations
    char buffer[BUFF_SIZE] = {0};
    char hello[BUFF_SIZE];
    strcpy(hello,"new message");


    //create new Socket based Server.
    ServerSocket myServer;

    //setup new server
    myServer.setPort(DEFAULT_PORT);
    myServer.init();

    //Put server into pasive listening mode.
    myServer.passiveRead(buffer,BUFF_SIZE);

    //print recieved message
    printf("%s\n",buffer );


    myServer.activeSend(hello,strlen(hello));


    printf("Hello message sent\n");
    return 0;
}