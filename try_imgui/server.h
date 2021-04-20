#pragma once

#include <iostream>
#include <cpr/cpr.h>
#include <string>

std::string urlEncode(std::string str){
    std::string new_str = "";
    char c;
    int ic;
    const char* chars = str.c_str();
    char bufHex[10];
    int len = strlen(chars);

    for(int i=0;i<len;i++){
        c = chars[i];
        ic = c;
        // uncomment this if you want to encode spaces with +
        /*if (c==' ') new_str += '+';
        else */if (isalnum(c) || c == '-' || c == '_' || c == '.' || c == '~') new_str += c;
        else {
            sprintf(bufHex,"%X",c);
            if(ic < 16)
                new_str += "%0";
            else
                new_str += "%";
            new_str += bufHex;
        }
    }
    return new_str;
}

void put_on_server(const std::string& name, const std::string& info) {
    std::string url = "https://rest-api-python.goshazorabov.repl.co/api/add/" + urlEncode(name) + "/" + urlEncode(info);
    cpr::Response r = cpr::Get(cpr::Url{url});
    r.status_code;                  // 200
    r.header["content-type"];// application/json; charset=utf-8
    //std::cout << r.text << '\n';// JSON text string
}

std::string get_from_server(std::string name) {
    std::string url = "https://rest-api-python.goshazorabov.repl.co/api/name/" + urlEncode(name);
    cpr::Response r = cpr::Get(cpr::Url{url});
    r.status_code;                  // 200
    r.header["content-type"];// application/json; charset=utf-8
    //std::cout << r.text << std::endl;
    return r.text;
}
