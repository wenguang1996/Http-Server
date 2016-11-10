//
// Created by kerno on 16-11-9.
//

#include "Server.h"
#include "../Linker/Linker.h"

Server::Server() {
    //create socket
    sockfd = socket(AF_INET,SOCK_STREAM,0);

    //bind  the socket and address
    struct sockaddr_in serveraddr;
    memset(&serveraddr,0,sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(PORT);
    serveraddr.sin_addr.s_addr = INADDR_ANY;

    if(bind(sockfd,(struct sockaddr*)&serveraddr,sizeof(serveraddr)) < 0)
    {
        cerr<<"bind error"<<endl;
        cout<<errno<<endl;
        exit(1);
    }

    //listen
    if(listen(sockfd,SOMAXCONN) < 0)
    {
        cerr<<"listen error"<<endl;
        exit(1);
    }


}

void Server::onListen() {
    //link
    struct sockaddr_in clientaddr;
    socklen_t clientaddr_len = sizeof(clientaddr);
    while(1)
    {
        int fd = accept(sockfd,(struct sockaddr*)&clientaddr,&clientaddr_len);
        if(fd < 0)
        {
            cerr<<"accept error"<<endl;
            continue;
        }
        Linker *linker = new Linker(fd);
        linker->sendResponse();
    }
}
