#pragma once
#include <string>
#include <iostream>

namespace utils
{
    inline void print(const std::string &message)
    {
        std::cout << message << "\n";
    }

    inline void printError(const std::string &message)
    {
        std::cerr << "> [ERROR] " << message << "\n";
    }

}