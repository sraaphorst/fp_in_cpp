/**
 * listing2_10.cpp
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
    std::vector<Person> separated{people.size()};

    const auto last = std::copy_if(std::cbegin(people), std::cend(people), std::begin(separated),
            [](const auto &p) { return p.sex == FEMALE; });
    std::copy_if(std::cbegin(people), std::cend(people), last,
            [](const auto &p) { return p.sex == MALE; });

    std::vector<std::string> names{separated.size()};
    std::transform(std::cbegin(separated), std::cend(separated), std::begin(names),
                   [](const auto &p) { return p.name; });

    std::copy(std::cbegin(names), std::cend(names), std::ostream_iterator<std::string>(std::cout, "\n"));
}