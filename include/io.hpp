#pragma once

#include <cassert>
#include <cstdlib>
#include <cstdint>
#include <iostream>
#include <string>
#include <vector>
#include <array>

namespace NHomework2
{
    typedef enum Ipv4Octets
    {
        FIRST = 0,
        SECOND,
        THIRD,
        FOURTH,
        OCTET_NUM
    } EIpv4Octets;

    // ("",  '.') -> [""]
    // ("11", '.') -> ["11"]
    // ("..", '.') -> ["", "", ""]
    // ("11.", '.') -> ["11", ""]
    // (".11", '.') -> ["", "11"]
    // ("11.22", '.') -> ["11", "22"]
    std::vector<std::string> Split(const std::string &str, char d);
    std::array<uint8_t, OCTET_NUM> Parse(const std::string &str_ip);
    void PrintOut(std::vector<std::array<uint8_t, OCTET_NUM>> &ip_map_l);
    void PrintOut(std::vector<std::array<uint8_t, OCTET_NUM>> &&ip_map_r);
} // namespace NHomework2
