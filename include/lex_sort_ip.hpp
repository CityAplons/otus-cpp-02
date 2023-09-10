#pragma once

#include <vector>
#include <string>

#define IPv4_OCTET_NUM  4

// Assuming that IP pool represented as a vector of IPv4 octets
void ip_SortLexicographically(std::vector<std::vector<std::string>> &pool);
void ip_SortLexicographicallyReversed(std::vector<std::vector<std::string>> &pool);
