#include <iostream>

#include "convertible_number.hpp"
#include "helpers.cpp"

numsys::ConvertibleNumber::ConvertibleNumber(int base10Num, const CharacterMap &characterMap)
    : m_numStored(base10Num), m_characterMap(characterMap)
{
}

void numsys::ConvertibleNumber::SetBaseWithMap(const std::string &stringMap)
{
    m_characterMap.clear();

    for (size_t i = 0; i < stringMap.size(); i++)
    {
        m_characterMap[i] = stringMap.at(i);
    }
}

void numsys::ConvertibleNumber::SetBaseWithMap(const CharacterMap &newMap)
{
    m_characterMap = newMap;
}

void numsys::ConvertibleNumber::SetDefaultBase(size_t base)
{
    if (base < 2 || base > 62)
    {
        utils::printError("Base must be in range [2, 62], defaulting to base 2 (binary)");
        base = 2; // default to base 2
    }

    m_characterMap.clear();

    for (size_t i = 0; i < base; i++)
    {
        // below 10 use characters 0-9
        if (i < 10)
        {
            m_characterMap[i] = '0' + i;
        }
        // above 10 use characters a-z
        else if (i < 36)
        {
            m_characterMap[i] = 'a' + (i - 10); // -10 to offset back to 0 i.e 11 -> 'a'
        }
        // above 36 use characters A-Z
        else
        {
            m_characterMap[i] = 'A' + (i - 36); // -36 to offset back to 0 i.e 37 -> 'A'
        }
    }
}

void numsys::ConvertibleNumber::ClearMap()
{
    m_characterMap.clear();
}

void numsys::ConvertibleNumber::SetNumber(const std::string &numberString)
{
    int result;

    const size_t base = m_characterMap.size();

    // principle
    // we need to store number in base 10
    // number is given in base `base`
    // to convert from base `base` to base 10
    // and store this as int

    // cache reverse map i.e a way to go from character to value
    // for performance
    std::unordered_map<char, int> reverseMap;
    for (const auto &[key, value] : m_characterMap)
        reverseMap[value] = key;

    // looping over characters in reverse and skipping
    for (size_t i = numberString.size(); i > 0; i--)
    {
        char currentChar = numberString.at(i - 1); // -1 to convert size to index

        // find corresponding value of character in reverse map
        int charValue = reverseMap.contains(currentChar) ? reverseMap[currentChar] : -1; // -1 to indicate not found

        if (charValue == -1)
        {
            utils::printError("Character {" + std::string(1, currentChar) + "} not found in character map, treating as 0");
            charValue = 0; // treat as zero
        }

        // add to result; base^(position from right, 0-indexed)
        result += charValue * static_cast<int>(pow(base, numberString.size() - i));
    }

    // store number
    m_numStored = result;

    utils::print("Stored number (in base 10): " + std::to_string(m_numStored));
}

std::string numsys::ConvertibleNumber::AsString()
{
    std::string result;

    // if not character map given just return the number in base 10
    if (m_characterMap.empty())
    {
        utils::printError("Character map is empty. Returning base 10 representation of number.");
        return std::to_string(m_numStored);
    }

    // return first character from map if stored number is zero
    if (m_numStored == 0)
    {
        return std::string(1, m_characterMap.at(0)); // 0 is NOT INDEX but key
    }

    // basic principle:
    // stored number is in base 10
    // to convert a number from base 10 to `base N`
    // we just get the all remainders, while continously dividing with `N`
    // use this remainder to get required character

    const size_t base = m_characterMap.size();

    int nextNum = m_numStored;
    // repeatedly divide and take remainder
    while (nextNum > 0)
    {
        int remainder = nextNum % base; // recalculate remainder

        result = m_characterMap.at(remainder) + result; // prepend character for current remainder

        // get nuxt number
        nextNum = static_cast<int>(nextNum / base); // static_cast<int> use to explicitly mention that decimals are discarded
    }

    return result;
}
