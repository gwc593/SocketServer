// Server side C/C++ program to demonstrate Socket programming

#ifdef __APPLE__
#include<SocketFunctionsOSX.hpp>

#else
#include<SocketFunctionsOSX.hpp>
#endif



int main(int argc, char const *argv[])
{
    //declarations
    char buffer[BUFF_SIZE];


    //create new Socket based Server.
    ServerSocket myServer;

    //setup new server
    myServer.setPort(DEFAULT_PORT);
    myServer.init();
    myServer.acceptNew();

/*    need tp develope a method for detecting when socket handle is no longer valid, then put
    into a loop where it can accept another connection.*/

    while(strcmp(buffer,"END_STREAM")){

        if(myServer.passiveRead(buffer, sizeof(buffer))){
            //print recieved message
            printf("%s\n",buffer );
        }

    }

    //clear up socket connection to release port for other users.
    myServer.Close();


    return 0;
}