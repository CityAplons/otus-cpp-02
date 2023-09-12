#include "sort.hpp"
#include "io.hpp"

#include <algorithm>
#include <cassert>

namespace NHomework2
{

    uint32_t String2Hex(std::vector<std::string> &ip)
    {
        assert(ip.size() >= OCTET_NUM);

        uint32_t result = 0;
        for (size_t i = 0; i < OCTET_NUM; ++i)
        {
            uint8_t num = static_cast<uint8_t>(std::stoi(ip[i]));
            result |= num << ((OCTET_NUM - i - 1) * 8);
        }

        return result;
    }

    void SortLexicographically(std::vector<std::vector<std::string>> &pool)
    {
        std::sort(pool.begin(), pool.end(), [](auto &a, auto &b)
                  { return String2Hex(a) < String2Hex(b); });
    }

    void SortLexicographicallyReversed(std::vector<std::vector<std::string>> &pool)
    {
        std::sort(pool.begin(), pool.end(), [](auto &a, auto &b)
                  { return String2Hex(b) < String2Hex(a); });
    }

} // namespace NHomework2
