#include "io.hpp"

namespace NHomework2
{
    void PrintOut(std::vector<std::array<uint8_t, OCTET_NUM>> &&ip_map_r)
    {
        PrintOut(ip_map_r);
    }

    void PrintOut(std::vector<std::array<uint8_t, OCTET_NUM>> &ip_map_l)
    {
        for (std::vector<std::array<uint8_t, OCTET_NUM>>::const_iterator ip =
                 ip_map_l.cbegin();
             ip != ip_map_l.cend(); ++ip)
        {
            for (std::array<uint8_t, OCTET_NUM>::const_iterator ip_part = ip->cbegin();
                 ip_part != ip->cend(); ++ip_part)
            {
                if (ip_part != ip->cbegin())
                {
                    std::cout << ".";
                }
                std::cout << std::to_string(*ip_part);
            }
            std::cout << std::endl;
        }
    }

    std::vector<std::string> Split(const std::string &str, char d)
    {
        std::vector<std::string> r;

        std::string::size_type start = 0;
        std::string::size_type stop = str.find_first_of(d);
        while (stop != std::string::npos)
        {
            r.push_back(str.substr(start, stop - start));

            start = stop + 1;
            stop = str.find_first_of(d, start);
        }

        r.push_back(str.substr(start));

        return r;
    }

    std::array<uint8_t, OCTET_NUM> Parse(const std::string &str_ip)
    {
        std::array<uint8_t, OCTET_NUM> r = {};

        auto octets = Split(str_ip, '.');
        assert(octets.size() == OCTET_NUM);

        for (size_t i = 0; i < OCTET_NUM; ++i)
        {
            r[i] = static_cast<uint8_t>(std::stoi(octets[i]));
        }

        return r;
    }
} // namespace NHomework2
