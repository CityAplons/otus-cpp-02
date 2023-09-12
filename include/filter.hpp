#pragma once

#include <tuple>

#include "io.hpp"

namespace NHomework2
{
    typedef enum FilterMode
    {
        FMODE_AND,
        FMODE_OR
    } EFilterMode;

    std::vector<std::vector<std::string>> SortByOctetValue(
        std::vector<std::vector<std::string>> &ip_map,
        std::vector<std::pair<EIpv4Octets, int>> mask,
        EFilterMode mode);
} // namespace NHomework2
