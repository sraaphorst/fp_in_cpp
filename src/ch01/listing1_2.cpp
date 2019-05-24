/**
 * listing1_2.cpp
 *
 * By Sebastian Raaphorst, 2019.
 */

#include <iostream>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <vector>

// uses std::count
int count_lines(const std::string &filename) {
    std::ifstream in{filename};
    return std::count(std::istreambuf_iterator<char>{in},
            std::istreambuf_iterator<char>{}, '\n');
}

std::vector<int>
count_lines_in_files(const std::vector<std::string> &files) {
    std::vector<int> results;

    // In original modification, used a for loop instead of transform.
    std::transform(std::cbegin(files), std::cend(files), std::back_inserter(results), count_lines);
    return results;
}

int main() {
    const std::vector<std::string> files{"listing1_1.cpp",
                                         "listing1_2.cpp",
                                         "listing1_4.cpp",
                                         "listing1_5.cpp"};
    const auto result = count_lines_in_files(files);
    std::copy(std::cbegin(result), std::cend(result), std::ostream_iterator<int>(std::cout, ","));
}

