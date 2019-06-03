/**
 * listing3_5.cpp
 *
 * By Sebastian Raaphorst, 2019.
 */

#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>


// *** CREATING A MUTABLE LAMBDA ****
int main() {
    int count = 0;
    std::vector<std::string> words{"An", "ancient", "pond"};

    std::for_each(std::cbegin(words), std::cend(words),
            [count](const std::string &word) mutable {
                if (!isupper(word[0])) {
                    std::cout << word << ' ' << count++ << '\n';
                }
    });
}