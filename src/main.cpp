// Server side C/C++ program to demonstrate Socket programming

#ifdef __APPLE__

#include<SocketFunctionsOSX.hpp>

#else
#include<SocketFunctionsOSX.hpp>
#endif


int main(int argc, char const *argv[]) {
    // TEST CLIENT CODE
    //declarations
    char buffer[BUFF_SIZE];

    ClientSocket myClient;
    myClient.setup("127.0.0.1", 8080);
    myClient.init();

   /* if(!myClient.activeSend("hello there unity, this is your first TCP message from the RDL team...outside companies... who needs em!")){
        printf("did get feedback");
    }
    else{
        printf("didnt get feedback");
    }
*/
    if(myClient.passiveRead(buffer,BUFF_SIZE)){
        printf("%s\n",buffer);
    }


/*
    //TEST SERVER CODE
    //declarations
    char buffer[BUFF_SIZE];

    ServerSocket myServer;

    myServer.init();
    myServer.acceptNew();

    while(true){
        if(myServer.passiveRead(buffer, BUFF_SIZE)){
            printf("recieved:%s\n");
        }
    }*/

    return 0;
}