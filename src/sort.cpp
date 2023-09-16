#include "sort.hpp"
#include "io.hpp"

#include <algorithm>

namespace NHomework2
{

    uint32_t Ip2Hex(std::array<uint8_t, OCTET_NUM> &ip)
    {
        assert(ip.size() >= OCTET_NUM);

        uint32_t result = 0;
        for (size_t i = 0; i < OCTET_NUM; ++i)
        {
            result |= ip[i] << ((OCTET_NUM - i - 1) * 8);
        }

        return result;
    }

    void SortLexicographically(std::vector<std::array<uint8_t, OCTET_NUM>> &pool)
    {
        std::sort(pool.begin(), pool.end(), [](auto &a, auto &b)
                  { return Ip2Hex(a) < Ip2Hex(b); });
    }

    void SortLexicographicallyReversed(std::vector<std::array<uint8_t, OCTET_NUM>> &pool)
    {
        std::sort(pool.begin(), pool.end(), [](auto &a, auto &b)
                  { return Ip2Hex(b) < Ip2Hex(a); });
    }

} // namespace NHomework2
