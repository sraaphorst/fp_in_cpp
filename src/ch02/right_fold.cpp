/**
 * right_fold.cpp
 *
 * By Sebastian Raaphorst, 2019.
 */

#include <iostream>
#include <algorithm>
#include <functional>
#include <iterator>
#include <numeric>

// Use right-fold to reverse a string.
// Instead of using normal iterators, use reverse iterators crbegin and crend.
std::string reverse(const std::string &text) {
    // Specify specifically std::string{} as the default here because "" indicates a char*
    // and thus we get our accumulator to be (char* char) -> char*, which we don't want.
    return std::accumulate(std::crbegin(text), std::crend(text), std::string{});
}

int main() {
    std::cout << reverse("The goose flies at night.") << '\n';
}