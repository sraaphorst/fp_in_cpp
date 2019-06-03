/**
 * listing3_1.cpp
 *
 * By Sebastian Raaphorst, 2019.
 */

#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

#include "person.h"

#include <range/v3/all.hpp>
#include <range/v3/view/all.hpp>
using namespace ranges;

struct age_filter {
    const int min_age;
    const int max_age;

    template<typename T>
    bool operator()(T&& t) const {
        return std::forward<T>(t).age >= min_age && std::forward<T>(t).age <= max_age;
    }
};

int main() {
    std::vector<Person> people{
            {"Sebastian Raaphorst", 41},
            {"Jeffery Raaphorst", 38},
            {"Kitty Litter", 1},
            {"Max the Cat", 12},
            {"Duncan the Cat", 10},
            {"Felix the Cat", 6},
            {"Kali the Cat", 1},
            {"Oliver the Cat", 0}
    };

    // Cannot be const. We don't need second half any more of transform because we overloaded << for ostream, People.
    auto youth = people | view::filter(age_filter{0, 35}); // view::transform([](const Person &p) { return p.name; });
    std::cout << ranges::view::all(youth) << '\n';
}