//
// Created by kerno on 16-11-17.
//

#ifndef HTTP_SERVER_SERVERERROREXCEPTION_H
#define HTTP_SERVER_SERVERERROREXCEPTION_H

#include <exception>
using namespace std;
class ServerErrorException : public  exception{
public:
    const char *what()  throw()
    {
        return msg;
    }
    ServerErrorException(char *msg)
    {
        this->msg = msg;
    }

private:
    char *msg;
};


#endif //HTTP_SERVER_SERVERERROREXCEPTION_H
