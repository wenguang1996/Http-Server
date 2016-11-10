//
// Created by kerno on 16-11-9.
//

#ifndef HTTP_SERVER_PARSER_H
#define HTTP_SERVER_PARSER_H


#include "../Request/Request.h"
#include "../Response/Response.h"

class Parser {
public:
    Parser(){}
    ~Parser(){}
    /// convert the request string to request object
    /// \param requestStr
    /// \param request
    void parseRequest(char *requestStr,Request &request);
    /// convert the reponse string to reponse object
    /// \param responseStr
    /// \param response
    void parseResponse(char *responseStr,Response &response);
    /// remove '\n'
    /// \param str
    string removeBlank(string str);
private:

};


#endif //HTTP_SERVER_PARSER_H
