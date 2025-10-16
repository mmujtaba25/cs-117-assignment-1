#pragma once
#include <unordered_map>

namespace numsys
{
    using CharacterMap = std::unordered_map<int, char>;

    inline const CharacterMap mapBinary = {
        {0, '0'}, {1, '1'}};

    inline const CharacterMap mapOctal = {
        {0, '0'}, {1, '1'}, {2, '2'}, {3, '3'}, {4, '4'}, {5, '5'}, {6, '6'}, {7, '7'}};

    inline const CharacterMap mapDecimal = {
        {0, '0'}, {1, '1'}, {2, '2'}, {3, '3'}, {4, '4'}, {5, '5'}, {6, '6'}, {7, '7'}, {8, '8'}, {9, '9'}};

    inline const CharacterMap mapHexadecimal = {
        {0, '0'}, {1, '1'}, {2, '2'}, {3, '3'}, {4, '4'}, {5, '5'}, {6, '6'}, {7, '7'}, {8, '8'}, {9, '9'}, {10, 'A'}, {11, 'B'}, {12, 'C'}, {13, 'D'}, {14, 'E'}, {15, 'F'}};
} // namespace numsys