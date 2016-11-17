//
// Created by kerno on 16-11-9.
//

#include <unistd.h>
#include "Linker.h"
#include "../Parser/Parser.h"
#include "../WebLogic/WebLogic.h"
#include "../ResponseCreater/ResponseCreater.h"
#include "../Exception/ResNotFoundException.h"

bool Linker::sendResponse() {

    WebLogic *webLogic = new WebLogic();
    Request *requestEn = new Request();
    Response *responseEn = new Response();
    Parser *parser = new Parser();
    try {
        this->getRequest();
    }catch (ServerErrorException &ex)
    {
        cout<<ex.what();
        return false;
    }

    try {
        parser->parseRequest(request,*requestEn);
    }catch (ServerErrorException &ex)
    {
        throw ex;
        return false;
    }


    if(requestEn->getRequsetMethod() == "POST")
    {
        webLogic->doPost(*requestEn,*responseEn);
    } else
    {
        webLogic->doGet(*requestEn,*responseEn);
    }
    string *response;
    response = ResponseCreater::createResponse(*responseEn);


    cout<<*response;
    if(write(clientSock,response->c_str(),response->size()) != response->size())
    {
        throw ServerErrorException("send error");
    }
    delete response;
}
void Linker::getRequest() throw(ServerErrorException){
    if (read(clientSock,request,REQUEST_MAX_SIZE) < 0)
    {
        throw ServerErrorException("read error");
    }
}
