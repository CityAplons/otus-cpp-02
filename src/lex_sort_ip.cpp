#include "lex_sort_ip.hpp"

#include <algorithm>
#include <cassert>
#include <cstdint>

uint32_t ip_String2Hex(std::vector<std::string> &ip)
{
    assert(ip.size() >= IPv4_OCTET_NUM);

    uint32_t result = 0;
    for (size_t i = 0; i < IPv4_OCTET_NUM; ++i)
    {
        uint8_t num = static_cast<uint8_t>(std::stoi(ip[i]));
        result |= num << ((IPv4_OCTET_NUM - i - 1) * 8);
    }

    return result;
}

void ip_SortLexicographically(std::vector<std::vector<std::string>> &pool)
{
    std::sort(pool.begin(), pool.end(), [](auto &a, auto &b)
              { return ip_String2Hex(a) < ip_String2Hex(b); });
}

void ip_SortLexicographicallyReversed(std::vector<std::vector<std::string>> &pool)
{
    std::sort(pool.begin(), pool.end(), [](auto &a, auto &b)
              { return ip_String2Hex(b) < ip_String2Hex(a); });
}