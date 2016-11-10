//
// Created by kerno on 16-11-9.
//

#include <unistd.h>
#include "Linker.h"
#include "../Parser/Parser.h"
#include "../WebLogic/WebLogic.h"
#include "../ResponseCreater/ResponseCreater.h"

bool Linker::sendResponse() {

    WebLogic *webLogic = new WebLogic();
    Request *requestEn = new Request();
    Response *responseEn = new Response();
    Parser *parser = new Parser();
    this->getRequest(),
    parser->parseRequest(request,*requestEn);

    if(requestEn->getRequsetMethod() == "POST")
    {
        webLogic->doPost(*requestEn,*responseEn);
    } else
    {
        webLogic->doGet(*requestEn,*responseEn);
    }
    string *response = ResponseCreater::createResponse(*responseEn);
    cout<<*response<<endl;
    if(write(clientSock,response->c_str(),response->size()) != response->size())
    {
        cerr<<"send error"<<endl;
        exit(1);
    }
}
void Linker::getRequest() {
    if (read(clientSock,request,REQUEST_MAX_SIZE) < 0)
    {
        cerr<<"read error"<<endl;
        exit(1);
    }


}
