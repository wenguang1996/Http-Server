//
// Created by kerno on 16-11-10.
//

#include <unistd.h>
#include <cstring>
#include "ResourceReader.h"

char *ResourceReader::readResource(const string &path) {
    FILE *fdin;
    string wholePath = "WebApp/";
    wholePath.append(path);
    fdin = fopen(wholePath.c_str(),"r");
    if (fdin == NULL)
    {
        cerr<<"open error"<<errno<<endl;
        exit(1);
    }
    long fileSize = 0;
    fseek(fdin,0,SEEK_END);
    fileSize = ftell(fdin);
    rewind(fdin);
    char *buffer = (char *)malloc(sizeof(char));
    if(buffer == NULL)
    {
        cerr<<"malloc error"<<endl;
        exit(1);
    }
    memset(buffer,0,fileSize);
    if( fileSize != fread(buffer,1,fileSize,fdin))
    {
        cerr<<"read error"<<errno<<endl;
        exit(1);
    }
    return buffer;

}
