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
    std::string name;
    Gender sex;
};

bool is_woman(const Person &p) {
    return p.sex == FEMALE;
}
