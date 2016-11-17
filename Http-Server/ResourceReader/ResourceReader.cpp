//
// Created by kerno on 16-11-10.
//

#include "ResourceReader.h"
#include "../Exception/ResNotFoundException.h"
#include "../Exception/ServerErrorException.h"

char *ResourceReader::readResource(const string &path) {
    FILE *fdin;
    string wholePath = "WebApp/";
    wholePath.append(path);
    fdin = fopen(wholePath.c_str(),"r");
    if (fdin == NULL)
    {
        throw ResNotFoundException();
    }
    long fileSize = 0;
    fseek(fdin,0,SEEK_END);
    fileSize = ftell(fdin);
    rewind(fdin);
    char *buffer = (char *)malloc(sizeof(char));
    if(buffer == NULL)
    {
        throw ServerErrorException("malloc error");
    }
    memset(buffer,0,fileSize);
    if( fileSize != fread(buffer,1,fileSize,fdin))
    {
        throw ServerErrorException("read resource error");
    }
    return buffer;

}
