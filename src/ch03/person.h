/**
 * person.h
 *
 * By Sebastian Raaphorst, 2019.
 */

#include <ostream>

struct Person {
    const std::string name;
    const int age;
};

std::ostream &operator<<(std::ostream &out, const Person &p) {
    return out << p.name;
}
