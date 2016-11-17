//
// Created by kerno on 16-11-17.
//

#ifndef HTTP_SERVER_RESNOTFOUNDEXCEPTION_H
#define HTTP_SERVER_RESNOTFOUNDEXCEPTION_H


#include <exception>
#include <iostream>
using namespace std;

class ResNotFoundException : public exception{
    const char *what() const throw()
    {
        return "ERROR! cannot find the resource!\n";
    }

};


#endif //HTTP_SERVER_RESNOTFOUNDEXCEPTION_H
