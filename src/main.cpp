#include <iostream>
#include "convertible_number.hpp"

int main()
{
    while (true)
    {
        std::cout << "Enter a base 10 number (or -1 to exit): ";
        int base10Num;
        std::cin >> base10Num;

        if (base10Num == -1)
        {
            break;
        }

        numsys::ConvertibleNumber number(base10Num);

        number.SetBaseWithMap(numsys::mapBinary);
        std::cout << "Binary: " << number.AsString() << std::endl;
        number.SetBaseWithMap(numsys::mapOctal);
        std::cout << "Octal: " << number.AsString() << std::endl;
        number.SetBaseWithMap(numsys::mapHexadecimal);
        std::cout << "Hexadecimal: " << number.AsString() << std::endl;
        number.SetDefaultBase(32);
        std::cout << "Base 32: " << number.AsString() << std::endl;
    }

    std::cout << "Exiting program. Press Enter to close." << std::endl;
    std::cin.ignore();
    std::cin.get();
    return 0;
}
