#include <iostream>
#include "Response/Response.h"
#include "Request/Request.h"
#include "Server/Server.h"

int main(int argc,char *argv[]) {
    Server * server = new Server();
    server ->onListen();
    return 0;
}