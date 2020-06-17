#include <iostream>
#include "headers.h"
#include <iostream>

int main(void)
{
    Headers head;

    if(!head.parceHttpHeader("../http.txt"))
    {
       std::cout << "Parce error" << std::endl;
       exit(-1);
    }

    std::cout << "Parced header" << std::endl;
    std::cout << std::endl;

    std::cout << "Request type" << std::endl;
    std::cout << head.getType() << ' ' << head.getTypeStr() << std::endl;
    std::cout << std::endl;

    std::cout << "Search by key" << std::endl;
    std::cout << head["Accept"] << std::endl;
    std::cout << std::endl;

    std::cout << "Enumeration" << std::endl;
    for(auto el : head)
    {
        std::cout << el.second << std::endl;
    }

    system("pause");
    return 0;
}
