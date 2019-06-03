/**
 * person.h
 *
 * By Sebastian Raaphorst, 2019.
 */

#include <ostream>

struct Person {
    // We need to be able to swap, so we can't mark these as const.
    std::string name;
    int age;
};

std::ostream &operator<<(std::ostream &out, const Person &p) {
    return out << p.name;
}
