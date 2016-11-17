//
// Created by kerno on 16-11-9.
//

#ifndef HTTP_SERVER_LINKER_H
#define HTTP_SERVER_LINKER_H

#include <sys/socket.h>
#include <netinet/in.h>
#include <cstring>
#include <iostream>
#include "../Exception/ServerErrorException.h"

//the max size of request
#define REQUEST_MAX_SIZE 1024

using namespace std;
class Linker {
public:
    Linker(int fd):clientSock(fd){
        request = new char[REQUEST_MAX_SIZE];
        if(request == NULL)
        {
            throw ServerErrorException("new memery error\n");
        }
    }
    ~Linker(){
        delete request;
    }

    /// send http response
    /// \return the send result
    bool sendResponse();

    /// get the request from client
    /// \return string point and give it to parser to parse
    void getRequest() throw(ServerErrorException);

private:
    int clientSock;
    char *request;

};


#endif //HTTP_SERVER_LINKER_H
