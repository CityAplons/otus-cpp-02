#include "io.hpp"

namespace NHomework2
{
    void PrintOut(std::vector<std::vector<std::string>> &&ip_map_r)
    {
        PrintOut(ip_map_r);
    }

    void PrintOut(std::vector<std::vector<std::string>> &ip_map_l)
    {
        for (std::vector<std::vector<std::string>>::const_iterator ip =
                 ip_map_l.cbegin();
             ip != ip_map_l.cend(); ++ip)
        {
            for (std::vector<std::string>::const_iterator ip_part = ip->cbegin();
                 ip_part != ip->cend(); ++ip_part)
            {
                if (ip_part != ip->cbegin())
                {
                    std::cout << ".";
                }
                std::cout << *ip_part;
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
} // namespace NHomework2
