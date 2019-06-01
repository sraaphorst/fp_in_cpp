/**
 * listing2_8.cpp
 *
 * By Sebastian Raaphorst, 2019.
 */

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

#include "person.h"

int main() {
    // Since we aren't changing the vector, this can be const.
    const std::vector<Person> people = {
            {"Joshua",      MALE},
            {"Janice",      FEMALE},
            {"George",      MALE},
            {"Alexander",   MALE},
            {"Judith",      FEMALE},
            {"Layla",       FEMALE},
            {"Christopher", MALE}
    };

    // Copy the women over to another container.
    std::vector<Person> women;
    std::copy_if(std::cbegin(people), std::cend(people), std::back_inserter(women),
            [](const auto &p) { return p.sex == FEMALE; });


    // We know the size of women so we can set it immediately to avoid memory reallocs.
    // We also don't have to use back_inserter, then.
    std::vector<std::string> names{women.size()};
    std::transform(std::cbegin(women), std::cend(women), std::begin(names),
                   [](const auto &p) { return p.name; }
    );

    std::copy(std::cbegin(names), std::cend(names), std::ostream_iterator<std::string>(std::cout, "\n"));
}