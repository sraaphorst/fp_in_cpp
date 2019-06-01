/**
 * listing1_5.cpp
 *
 * By Sebastian Raaphorst, 2019.
 */

#include <iostream>
#include <algorithm>
#include <fstream>
#include <iterator>
#include <vector>

// https://ericniebler.github.io/range-v3
#include <range/v3/all.hpp>
#include <range/v3/view/all.hpp>
using namespace ranges;


auto open_file(const std::string &filename) {
    return std::ifstream{filename};
}

// Note that this function MUST accept an rvalue!
auto count_lines(std::ifstream &&in) {
    return std::count(std::istreambuf_iterator<char>{in},
                      std::istreambuf_iterator<char>{}, '\n');
}

auto count_lines_in_files(const std::vector<std::string> &filenames) {
    return filenames | view::transform(open_file) | view::transform(count_lines);
}

int main() {
    const std::vector<std::string> files{"listing1_1.cpp",
                                         "listing1_2.cpp",
                                         "listing1_4.cpp",
                                         "listing1_5.cpp"};
    std::cout << ranges::view::all(count_lines_in_files(files)) << '\n';
}
