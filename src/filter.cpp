#include "filter.hpp"

#include <algorithm>

namespace NHomework2
{
    std::vector<std::vector<std::string>> FilterByOctetValue(
        std::vector<std::vector<std::string>> &ip_map,
        std::vector<std::pair<EIpv4Octets, int>> mask,
        EFilterMode mode)
    {
        std::vector<std::vector<std::string>> ret;

        auto CheckOctet = [mask, mode](std::vector<std::string> ip)
        {
            bool result = false;
            if (mode == FMODE_AND)
                result = true;

            for (auto &&submask : mask)
            {
                int value;
                EIpv4Octets position;
                std::tie(position, value) = submask;

                if (value < 0 || value > 255)
                {
                    result = false;
                    break;
                }

                switch (mode)
                {
                case FMODE_AND:
                    result &= std::stoi(ip[position]) == value;
                    break;
                case FMODE_OR:
                    result |= std::stoi(ip[position]) == value;
                    break;
                default:
                    break;
                }
            }
            return result;
        };

        typedef std::vector<std::vector<std::string>>::iterator TIterator;
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
