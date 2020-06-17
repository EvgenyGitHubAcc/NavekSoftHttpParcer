#include <iostream>
#include "headers.h"
#include <iostream>

int main(void)
{
    Headers head;

    std::cout << "Parce header" << std::endl;
    std::cout << head.parceHttpHeader("http.txt") << std::endl;
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
