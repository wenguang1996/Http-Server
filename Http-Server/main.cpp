#include <iostream>
#include "Response/Response.h"
int main() {
    Response res;
    res.setHeader("get","test.html");
    vector<pair<string,string>> *headers = res.getHeaders();
    vector<pair<string,string>>::iterator it;
    for(it = headers->begin();it != headers->end();it++)
    {
        cout<<it->first<<"  "<<it->second;
    }
    return 0;
}