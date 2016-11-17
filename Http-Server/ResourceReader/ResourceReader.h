//
// Created by kerno on 16-11-10.
//

#ifndef HTTP_SERVER_RESOURCEREADER_H
#define HTTP_SERVER_RESOURCEREADER_H

#include <fcntl.h>
#include <iostream>
#include <string>
#include <sys/stat.h>
#include <unistd.h>
#include <cstring>
using  namespace std;

class ResourceReader {
public:
    static char *readResource(const string &path);

};


#endif //HTTP_SERVER_RESOURCEREADER_H
