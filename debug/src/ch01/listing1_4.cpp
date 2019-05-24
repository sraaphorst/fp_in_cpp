/**
 * listing1_4.cpp
 *
 * By Sebastian Raaphorst, 2019.
 */

#include <iostream>
#include <fstream>

#include <range/v3/all.hpp>
#include <range/v3/view/all.hpp>
using namespace ranges;

auto count_lines(const std::string &filename) {
    std::ifstream in{filename};
    return std::count(std::istreambuf_iterator<char>{in},
                      std::istreambuf_iterator<char>{}, '\n');
}

auto count_lines_in_files(const std::vector<std::string> &files) {
    return files | view::transform(count_lines);
}

int main() {
    const std::vector<std::string> files{"listing1_1.cpp",
                                         "listing1_2.cpp",
                                         "listing1_4.cpp",
                                         "listing1_5.cpp"};
    std::cout << ranges::view::all(count_lines_in_files(files)) << '\n';
}
