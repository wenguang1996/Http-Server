//
// Created by kerno on 16-11-9.
//

#ifndef HTTP_SERVER_SERVER_H
#define HTTP_SERVER_SERVER_H
#include <sys/socket.h>
#include <netinet/in.h>
#include <cstring>
#include <iostream>

#define PORT 11130
using namespace std;

class Server {
public:
    Server();
    void onListen();

private:
    int sockfd;
};


#endif //HTTP_SERVER_SERVER_H
