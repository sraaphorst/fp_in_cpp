/**
 * people.cpp
 *
 * By Sebastian Raaphorst, 2019
 */

#include <iostream>
#include <vector>

#include <algorithm>
#include <iterator>

#include <range/v3/all.hpp>
#include <range/v3/view/all.hpp>
using namespace ranges;

enum Gender { MALE, FEMALE };

struct Person {
    const std::string name;
    const Gender sex;
};

bool is_woman(const Person &p) {
    return p.sex == FEMALE;
}

const std::string get_name(const Person &p) {
    return p.name;
}

/**
 * See comment below about men_names.
 */
auto women_names(const std::vector<Person> &people) {
    return people | view::filter(is_woman) | view::transform(get_name);
}

/**
 * If this is const auto, we can do:
 *
 * auto men = men_names(people);
 * std::cout << ranges::view::all(men) << '\n';
 *
 * but we can't do:
 *
 * std::cout << ranges::view::all(men_names(people)) << '\n';
 *
 * In any case, we cannot do:
 * const auto men = ...
 * ...
 */
auto men_names(const std::vector<Person> &people) {
    return people |
    view::filter([](const auto &p) { return p.sex == MALE; }) |
    view::transform([] (const auto &p) { return p.name; });
}

int main() {
    const std::vector<Person> people = {
            {"Joshua", MALE},
            {"Janice", FEMALE},
            {"George", MALE},
            {"Alexander", MALE},
            {"Judith", FEMALE},
            {"Layla", FEMALE},
            {"Christopher", MALE}
    };

    std::cout << ranges::view::all(women_names(people)) << '\n';
    std::cout << ranges::view::all(men_names(people)) << '\n';
}