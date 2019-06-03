/**
 * person.h
 *
 * By Sebastian Raaphorst, 2019.
 */

#pragma once

enum Gender { MALE, FEMALE };

// *** Separate the people by gender manually. ***
// Showing the power of the STL algorithms.
struct Person {
    // We need to be able to swap, so we cannot mark these const.
    std::string name;
    Gender sex;
    int age = -1; // unspecified
};

bool is_woman(const Person &p) {
    return p.sex == FEMALE;
}
