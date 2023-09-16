#include "filter.hpp"

#include <algorithm>

namespace NHomework2
{
    std::vector<std::array<uint8_t, OCTET_NUM>> FilterByOctetValue(
        std::vector<std::array<uint8_t, OCTET_NUM>> &ip_map,
        std::vector<std::pair<EIpv4Octets, uint8_t>> mask,
        EFilterMode mode)
    {
        std::vector<std::array<uint8_t, OCTET_NUM>> ret;

        auto CheckOctet = [mask, mode](std::array<uint8_t, OCTET_NUM> ip)
        {
            bool result = false;
            if (mode == FMODE_AND)
                result = true;

            for (auto &&submask : mask)
            {
                int value;
                EIpv4Octets position;
                std::tie(position, value) = submask;

                switch (mode)
                {
                case FMODE_AND:
                    result &= ip[position] == value;
                    break;
                case FMODE_OR:
                    result |= ip[position] == value;
                    break;
                default:
                    break;
                }
            }
            return result;
        };

        using TIterator = std::vector<std::array<uint8_t, OCTET_NUM>>::iterator;
        std::vector<TIterator> itList;
        auto running = ip_map.begin(), end = ip_map.end();
        while (running != end)
        {
            running = std::find_if(running, end, CheckOctet);
            if (running != end)
                itList.emplace_back(running++);
        }

        for (auto &&iterator : itList)
        {
            ret.emplace_back(*iterator);
        }

        return ret;
    }
} // namespace NHomework2
