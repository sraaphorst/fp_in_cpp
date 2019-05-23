/**
 * listing1_4.cpp
 *
 * By Sebastian Raaphorst, 2019.
 */

#include "listing1_4.h"
#include <algorithm>
#include <fstream>

#include <range/v3/all.hpp>

using namespace ranges;

int count_lines(const std::string &filename) {
    std::ifstream in{filename};
    return std::count(std::istreambuf_iterator<char>{in},
                      std::istreambuf_iterator<char>{}, '\n');
}

std::vector<int>
const lines_in_files(const std::vector<std::string> &filenames) {
    return filenames | view::transform(count_lines);
}