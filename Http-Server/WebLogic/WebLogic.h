//
// Created by kerno on 16-11-10.
//

#ifndef HTTP_SERVER_WEBLOGIC_H
#define HTTP_SERVER_WEBLOGIC_H

#include <string>
#include "../Request/Request.h"
#include "../Response/Response.h"

using namespace std;

class WebLogic {
public:
    string *doGet(Request &request,Response &response);

    string *doPost(Request &request,Response &response);

};


#endif //HTTP_SERVER_WEBLOGIC_H
