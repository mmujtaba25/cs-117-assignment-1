#pragma once
#include <cstddef>
#include <string>
#include <constants.hpp>

namespace numsys
{
    class ConvertibleNumber
    {
    public:
        ConvertibleNumber(int base10Num = 0, const CharacterMap &map = numsys::mapHexadecimal);

        void SetBaseWithMap(const std::string &newMap);
        void SetBaseWithMap(const CharacterMap &newMap);
        void SetDefaultBase(size_t base);
        void ClearMap();

        void SetNumber(const std::string &numberString);

        std::string AsString();

    private:
        int m_numStored;
        CharacterMap m_characterMap;
    };

} // namespace numsys