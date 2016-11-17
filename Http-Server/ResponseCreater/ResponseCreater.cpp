//
// Created by kerno on 16-11-10.
//

#include "ResponseCreater.h"
#include "../Exception/ResNotFoundException.h"
#include "../Exception/ServerErrorException.h"

string *ResponseCreater::createResponse(Response &response) {
    string *responseStr = new string();
    string *head = new string("HTTP/1.1 ");
    for(vector<pair<string,string>>::iterator it = response.getHeaders()->begin();it != response.getHeaders()->end();it++)
    {
        responseStr->append(it->first);
        responseStr->append(":");
        responseStr->append(it->second);
        responseStr->append("\n");
    }
    try {
        responseStr->append(ResourceReader::readResource(response.getRes()));
    }catch (ResNotFoundException &ex)
    {
        head->append("404\n");
        head ->append(*responseStr);
        return head;
    }catch (ServerErrorException &ex)
    {
        head->append("500\n");
        head ->append(*responseStr);
        return head;
    }
    head->append("200\n");
    head ->append(*responseStr);
    delete responseStr;
    return head;

}
