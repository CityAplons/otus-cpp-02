#pragma once

#include <cassert>
#include <cstdlib>
#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

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
    void PrintOut(std::vector<std::vector<std::string>> ip_map);
} // namespace NHomework2
