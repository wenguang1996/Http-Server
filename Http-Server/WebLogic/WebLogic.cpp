//
// Created by kerno on 16-11-10.
//

#include "WebLogic.h"

string *WebLogic::doGet(Request &request, Response &response) {
//    response.setHeader("status","404");
//    response.setHeader("page","html");
    response.setRes("index.html");
    return nullptr;
}

string *WebLogic::doPost(Request &request, Response &response) {
    return nullptr;
}
