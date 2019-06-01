/**
 * listing2_14.cpp
 *
 * By Sebastian Raaphorst, 2019.
 */

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

#include "person.h"

// Tail-recursive implementation.
template<typename Filter, typename Iterator>
std::vector<std::string> names_for_helper(
        Iterator people_begin,
        Iterator people_end,
        Filter filter,
        std::vector<std::string> previously_collected) {

    if (people_begin == people_end)
        return previously_collected;

    const auto &head = *people_begin;

    if (filter(head))
        previously_collected.emplace_back(head.name);

    return names_for_helper(
            people_begin + 1,
            people_end,
            filter,
            std::move(previously_collected)
            );
}

template<typename Filter, typename Iterator>
std::vector<std::string> names_for(
        Iterator people_begin,
        Iterator people_end,
        Filter filter) {
    return names_for_helper(people_begin, people_end, filter, {});
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

    const auto women_names = names_for(std::cbegin(people), std::cend(people), [](const auto &p) { return p.sex == FEMALE; });
    std::copy(std::cbegin(women_names), std::cend(women_names), std::ostream_iterator<std::string>(std::cout, "\n"));
}