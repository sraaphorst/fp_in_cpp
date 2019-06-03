/**
 * listing3_2.cpp
 *
 * By Sebastian Raaphorst, 2019.
 *
 * Reaklly 3.2 ro 3.4.
 */

#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

#include "person.h"

class Company {
public:
    std::string team_name_for(const Person &employee) const;
    int count_team_members(const std::string &team_name) const;

private:
    std::vector<Person> m_employees;
};

int Company::count_team_members(const std::string &team_name) const {
    return std::count_if(std::cbegin(m_employees), std::cend(m_employees),
            [this, &team_name] (const Person &employee) {
                return team_name_for(employee) == team_name;
    });
}

// *** LAMBBDA IMPLEMENTATION ***
// As well as creating class, evaluating lambda creates an instance of that class called a closurem whith constains
// state or environment along with code that should be executed on that sate.
class lambda_implementation {
private:
    const Company *m_this;
    const std::string &m_team_name;

public:
    lambda_implementation(const Company *comp, const std::string &team_name)
            : m_this(comp), m_team_name(team_name) {}

    // NOTE: *** CONST BY DEFAULT ***
    // IF YOU WANT TO CHANGE VALUE OF CAPTURED VARIABLES< MUST USE MUTABLE KEYWORDD,
    bool operator()(const Person &employee) const {
        return m_this->team_name_for(employee) == m_team_name;
    }
};

int main() {

}