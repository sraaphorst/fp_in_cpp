/**
 * listing3_8.cpp
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

enum class ANIMAL { CAT, DOG };

struct Pet {
    std::string name;
    ANIMAL type;
    int age;
};


int main() {
    std::vector<Person> people{
            {"Sebastian Raaphorst", 41},
            {"Jeffery Raaphorst",   38},
            {"Kitty Litter",        1}
    };

    struct vector<Pet> animals{
            {"Max", ANIMAL::CAT, 12},
            {"Duncan", ANIMAL::CAT, 10},
            {"Felix", ANIMAL::CAT, 6},
            {"Kali", ANIMAL::CAT, 1},
            {"Oliver", ANIMAL::CAT, 0}
            {"Sonic", ANIMAL::DOG, 12}
    };

    // A lambda that creates a lambda that takes auto parameters so it can be used on anything with age
    // instead of relying on templates.
    auto age_filter = [](const int lower, const int upper) {
        return [](const auto &a) {
            return a.age >= lower && a.age <= upper;
        }
    };

    // Cannot be const. We don't need second half any more of transform because we overloaded << for ostream, People.
    std::cout << ranges::view::all(people | view::filter(age_filter(20, 45))) << '\n';
    std::cout << ranges::view::all(animals | view::filter(age_filter(5, 11))) << '\n';
}