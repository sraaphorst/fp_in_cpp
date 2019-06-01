/**
 * listing2_2.cpp
 *
 * By Sebastian Raaphorst, 2019.
 */

#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>

// Imperative average.
double average_score(const std::vector<double> &scores) {
    return std::accumulate(std::cbegin(scores), std::cend(scores), 0.0) / scores.size();
}

int main() {
    // Use std::reduce if you want parallelization, with an execution policy.
    const std::vector<double> scores = {
            33, 45, 65, 72, 81, 93, 98
    };

    std::cout << average_score(scores) << '\n';
}