#include <iostream>
#include "Response/Response.h"
#include "Request/Request.h"
#include "Server/Server.h"
#include "Exception/ServerErrorException.h"

int main(int argc,char *argv[]) {
    try {
        Server * server = new Server();
        server ->onListen();
    }catch (ServerErrorException &ex)
    {
        cout<<ex.what();
        return 0;
    }

    return 0;
}