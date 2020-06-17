#include "headers.h"

type Headers::getType() const
{
    return reqType;
}

std::string Headers::getTypeStr() const
{
    if(reqType == GET)
    {
        return std::string("GET");
    }
    else if (reqType == POST)
    {
        return std::string("POST");
    }
    else if (reqType == CONNECT)
    {
        return std::string("CONNECT");
    }
    else if (reqType == PUT)
    {
        return std::string("PUT");
    }
    else if (reqType == HEAD)
    {
        return std::string("HEAD");
    }
    else
    {
        return std::string("UNKNOWN");
    }
}

void Headers::setReqType(const std::string & req)
{
    if(req == "GET")
    {
        reqType = GET;
    }
    else if (req == "POST")
    {
        reqType = POST;
    }
    else if (req == "CONNECT")
    {
        reqType = CONNECT;
    }
    else if (req == "PUT")
    {
        reqType = PUT;
    }
    else if (req == "HEAD")
    {
        reqType = HEAD;
    }
    else
    {
        reqType = UNKNOWN;
    }
}

void Headers::setUrl(const std::string & str)
{
    url = std::move(str);
}

void Headers::setHttpVer(const std::string & str)
{
    httpVer = std::move(str);
}

void Headers::parceFirstStr(const std::string & line)
{
    std::regex reqTypeRegex("(.+)\\s(.+)\\s(HTTP\\/\\d+\\.\\d+)");
    std::smatch matches;
    std::regex_search(line, matches, reqTypeRegex);
    setReqType(matches[1]);
    setUrl(matches[2]);
    setHttpVer(matches[3]);
}

void Headers::parceHeaderStr(const std::string & line)
{
    std::regex reqTypeRegex("([\\w-]+): (.*)");
    std::smatch matches;
    std::regex_search(line, matches, reqTypeRegex);
    insert(std::pair<std::string, std::string>(matches[1], matches[2]));
}


bool Headers::parceHttpHeader(const std::string filename)
{
    std::fstream file;
    std::string line;
    file.open (filename, std::ios::in);

    if (!file.is_open())
    {
        return false;
    }

    getline(file, line);

    parceFirstStr(line);

    while (getline(file, line))
    {
        parceHeaderStr(line);
    }

    file.close();
    return true;
}

Headers::Headers()
{

}
