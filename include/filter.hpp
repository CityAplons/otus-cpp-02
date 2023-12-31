#pragma once

#include <tuple>

#include "io.hpp"

namespace NHomework2
{
    enum EFilterMode
    {
        FMODE_AND,
        FMODE_OR
    };
    using NHomework2::EFilterMode;

    std::vector<std::array<uint8_t, OCTET_NUM>> FilterByOctetValue(
        std::vector<std::array<uint8_t, OCTET_NUM>> &ip_map,
        std::vector<std::pair<EIpv4Octets, uint8_t>> mask,
        EFilterMode mode);
} // namespace NHomework2
