//
// Created by kerno on 16-11-10.
//

#ifndef HTTP_SERVER_RESPONSECREATER_H
#define HTTP_SERVER_RESPONSECREATER_H

#include <string>
#include "../Response/Response.h"
#include "../ResourceReader/ResourceReader.h"
using namespace std;

class ResponseCreater {
public:
    /// convert the reponse object ro string
    /// \param response
    /// \return
    static string *createResponse(Response &response);

};


#endif //HTTP_SERVER_RESPONSECREATER_H
