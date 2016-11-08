#include <iostream>
#include "Response/Response.h"
#include "Request/Request.h"
int main() {
    Response res;
    Request req;
    if(!res.setHeader("get","test.html"))
    {
        cerr<<"set error"<<endl;
    }
    vector<pair<string,string>> *headers;
    req.setHeaders(res.getHeaders());
    headers = req.getHeaders();
    vector<pair<string,string>>::iterator it;
    for(it = headers->begin();it != headers->end();it++)
    {
        cout<<it->first<<"  "<<it->second<<endl;
    }
    return 0;
}