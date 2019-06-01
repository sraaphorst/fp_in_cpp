/**
 * listing2_4.cpp
 *
 * By Sebastian Raaphorst, 2019.
 */

#include <iostream>
#include <algorithm>
#include <iterator>
#include <numeric>

// FOLDING algorithm to count the number of newspace characters in a block of text.
int num_newlines(const std::string &text) {
    return std::accumulate(std::cbegin(text), std::cend(text), 0,
                           [](int newlines, char c) {
                               return c == '\n' ? newlines + 1 : newlines;
                           });
}

int main() {
    const std::string text = "What does the fox say?\n"
                             "Cat says meow\n"
                             "Dog says woof\n"
                             "Elephant says oompaloof\n";
    std::cout << num_newlines(text) << '\n';
}