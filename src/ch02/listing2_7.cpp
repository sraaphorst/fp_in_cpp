/**
 * listing2_7.cpp
 *
 * By Sebastian Raaphorst, 2019.
 */

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

#include "person.h"

int main() {
    // Since we are changing the vector, this cannot be const.
    std::vector<Person> people = {
            {"Joshua",      MALE},
            {"Janice",      FEMALE},
            {"George",      MALE},
            {"Alexander",   MALE},
            {"Judith",      FEMALE},
            {"Layla",       FEMALE},
            {"Christopher", MALE}
    };

    // 1. remove_if moves all people to the end of the list and returns an iterator.
    // 2. erase erases all of those people.
    people.erase(
            // Moves the people to the end of the list and returns an iterator.
            std::remove_if(std::begin(people), std::end(people), [](const auto &p) { return p.sex == MALE; }),
            std::end(people)
    );

    std::vector<std::string> names;
    std::transform(std::cbegin(people), std::cend(people), std::back_inserter(names),
            [](const auto &p) { return p.name; }
    );

    std::copy(std::cbegin(names), std::cend(names), std::ostream_iterator<std::string>(std::cout, "\n"));
}