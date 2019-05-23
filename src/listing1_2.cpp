/**
 * listing1_2.cpp
 *
 * By Sebastian Raaphorst, 2019.
 */

#include <algorithm>
#include <iterator>
#include <fstream>
#include <vector>

int count_lines(const std::string &filename) {
    std::ifstream in{filename};
    return std::count(std::istreambuf_iterator<char>{in},
            std::istreambuf_iterator<char>{}, '\n');
}

std::vector<int>
count_lines_in_files(const std::vector<std::string> &files) {
    std::vector<int> results;

    // In original modification, used a for loop instead of transform.
    std::transform(std::cbegin(files), std::cend(files), results, count_lines);
}
