/**
 * listing2_5.cpp
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

    // Make a copy of the vector to show the difference between partition and stable_partirtion:
    std::vector<Person> people2 = people;

    // PARTITION: Order is not naturally kept.
    auto iter1 = std::partition(std::begin(people), std::end(people), is_woman);
    std::cout << "Women (unstable):\n";
    for (auto i = std::begin(people); i != iter1; ++i)
        std::cout << '\t' << i->name << '\n';
    std::cout << "Men (unstable):\n";
    for (auto i = iter1; i != std::end(people); ++i)
        std::cout << '\t' << i->name << '\n';

    // STABLE PARTITION: Order is kept.
    auto iter2 = std::stable_partition(std::begin(people2), std::end(people2), is_woman);
    std::cout << "Women (stable):\n";
    for (auto i = std::begin(people2); i != iter2; ++i)
        std::cout << '\t' << i->name << '\n';
    std::cout << "Men (stable):\n";
    for (auto i = iter2; i != std::end(people2); ++i)
        std::cout << '\t' << i->name << '\n';
}