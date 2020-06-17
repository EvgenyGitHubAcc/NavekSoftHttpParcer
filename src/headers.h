#ifndef HEADERS_H
#define HEADERS_H

#include <map>
#include <fstream>
#include <iostream>
#include <regex>

enum type {GET,POST,CONNECT,PUT,HEAD, UNKNOWN};

class Headers : public std::map<std::string, std::string>
{
private:
    enum type reqType;
    std::string url;
    std::string httpVer;
    void setReqType(const std::string &);
    void setUrl(const std::string &);
    void setHttpVer(const std::string &);
    void parceFirstStr(const std::string &);
    void parceHeaderStr(const std::string &);
public:
    enum type getType() const;
    std::string getTypeStr() const;
    bool parceHttpHeader(const std::string filename);
    Headers();
};



#endif // HEADERS_H
