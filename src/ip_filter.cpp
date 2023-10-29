#include "io.hpp"
#include "sort.hpp"
#include "filter.hpp"

int main(int argc, char const *argv[])
{
    (void)argc;
    (void)argv;

    using namespace NHomework2;

    try
    {
        std::vector<std::array<uint8_t, OCTET_NUM>> ip_pool;

        for (std::string line; std::getline(std::cin, line);)
        {
            std::string ip = Split(line, '\t').at(0);
            ip_pool.push_back(Parse(ip));
        }

        // reverse lexicographically sort
        SortLexicographicallyReversed(ip_pool);
        PrintOut(ip_pool);

        // filter by first byte and output
        PrintOut(FilterByOctetValue(ip_pool, {{FIRST, 1}}, FMODE_OR));

        // filter by first and second bytes and output
        PrintOut(FilterByOctetValue(ip_pool, {{FIRST, 46}, {SECOND, 70}}, FMODE_AND));

        // filter by any byte and output
        PrintOut(FilterByOctetValue(ip_pool, {{FIRST, 46}, {SECOND, 46}, {THIRD, 46}, {FOURTH, 46}}, FMODE_OR));
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
