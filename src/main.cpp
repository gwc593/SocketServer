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


    //create new Socket based Server.
    ServerSocket myServer;

    //setup new server
    myServer.setPort(DEFAULT_PORT);
    myServer.init();
    myServer.acceptNew();

    while(true){

        if(myServer.passiveRead(buffer, sizeof(buffer))){
            //print recieved message
            printf("%s\n",buffer );
        }

    }

    //clear up socket connection to release port for other users.
    myServer.Close();


    return 0;
}