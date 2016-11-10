//
// Created by kerno on 16-11-10.
//

#include "ResponseCreater.h"

string *ResponseCreater::createResponse(Response &response) {
    string *responseStr = new string();
    for(vector<pair<string,string>>::iterator it = response.getHeaders()->begin();it != response.getHeaders()->end();it++)
    {
        responseStr->append(it->first);
        responseStr->append(":");
        responseStr->append(it->second);
        responseStr->append("\n");
    }
    responseStr->append(ResourceReader::readResource(response.getRes()));
    return responseStr;

}
