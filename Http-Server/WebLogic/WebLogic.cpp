//
// Created by kerno on 16-11-10.
//

#include "WebLogic.h"

string *WebLogic::doGet(Request &request, Response &response) {

//    if(request.getRequestResource() == "/")
//    {
//        response.setRes("index.html");
//    }
//    else
//    {
//        response.setRes(request.getRequestResource());
//    }
    response.setRes("index.html");
    return nullptr;
}

string *WebLogic::doPost(Request &request, Response &response) {
    return nullptr;
}
