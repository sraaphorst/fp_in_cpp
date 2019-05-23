/**
 * listing1_1.h
 *
 * By Sebastian Raaphorst, 2019.
 */

#include <fstream>
#include <utility>
#include <vector>

std::vector<int>
count_lines_in_files(const std::vector<std::string> &files) {
    std::vector<int> results;
    char c = 0;

    for (const auto &filename: files) {
        int line_count = 0;
        std::ifstream in{filename};

        while (in.get(c)) {
            if (c == '\n')
                ++line_count;
        }

        results.emplace_back(line_count);
    }

    // This is NRVO: non-return value optimized.
    // The compiler automatically optimizes this so we don't need a move.
    // return std::move(results);
    return results;
}
