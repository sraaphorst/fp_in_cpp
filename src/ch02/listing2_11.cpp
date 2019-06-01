/**
 * listing2_11.cpp
 *
 * By Sebastian Raaphorst, 2019.
 */

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

#include "person.h"

// Filter using template to get names of people.
template<typename Filter>
std::vector<std::string> names_for(const std::vector<Person> &people, Filter filter) {
    std::vector<std::string> result;

    // Using a hand-written loop is strongly advised against, but in this case, it is simple enough.
    for (const auto &p: people)
        if (filter(p))
            result.emplace_back(p.name);

    return result;
}

int main() {
    const std::vector<Person> people = {
            {"Joshua",      MALE},
            {"Janice",      FEMALE},
            {"George",      MALE},
            {"Alexander",   MALE},
            {"Judith",      FEMALE},
            {"Layla",       FEMALE},
            {"Christopher", MALE}
    };

    const auto women_names = names_for(people, [](const auto &p) { return p.sex == FEMALE; });
    std::copy(std::cbegin(women_names), std::cend(women_names), std::ostream_iterator<std::string>(std::cout, "\n"));
}