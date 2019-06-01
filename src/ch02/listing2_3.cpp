/**
 * listing2_3.cpp
 *
 * By Sebastian Raaphorst, 2019.
 */

#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>

// Using accumulate for an operation other than addition, in this case, to calculate factorial.
int factorial(int n) {
    std::vector<int> factors;
    factors.resize(n);
    std::iota(std::begin(factors), std::end(factors), 1);

    return std::accumulate(std::cbegin(factors), std::cend(factors), 1, std::multiplies<int>{});
}

int main() {
    std::cout << "10! = " << factorial(10) << '\n';
}