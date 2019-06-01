/**
 * listing2_12.cpp
 *
 * By Sebastian Raaphorst, 2019.
 */

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

#include "person.h"

// Naive recursive implementation: not tail-recursive.
template<typename Filter, typename Iterator>
std::vector<std::string> names_for(Iterator people_begin, Iterator people_end, Filter filter) {
    if (people_begin == people_end)
        return {};

    const auto &head = *people_begin;
    std::vector<std::string> processed_tail = names_for(
            people_begin + 1,
            people_end,
            filter
            );

    if (filter(head))
        processed_tail.insert(std::begin(processed_tail), head.name);
    return processed_tail;
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
