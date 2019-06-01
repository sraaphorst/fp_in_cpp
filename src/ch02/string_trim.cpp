/**
 * string_trim.cpp
 *
 * By Sebastian Raaphorst, 2019.
 */

#include <iostream>
#include <algorithm>
#include <functional>
#include <iterator>
#include <numeric>

bool is_not_space(char c) {
    return c != ' ' && c != '\t';
}


// Note we pass by value here so that:
// 1. We don't have to make a copy inside the method, as we are working directly on s; and
// 2. In this was, we can handle r-values.
std::string trim_left(std::string s) {
    s.erase(std::begin(s),
            std::find_if(std::begin(s), std::end(s), is_not_space));
    return s;
}

// *base* converts a reverse iterator into its corresponding iterator!!!
std::string trim_right(std::string s) {
    s.erase(std::find_if(std::rbegin(s), std::rend(s), is_not_space).base(), s.end());
    return s;
}

// Composition:
std::string trim(std::string s) {
    // We have a copy of the strings already, so move it.
    return trim_left(std::move(trim_right(std::move(s))));
}

int main() {
    std::cout << "\"" << trim("   \t  This is nice.   \t\t\t") << "\"\n";
}