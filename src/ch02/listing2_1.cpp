/**
 * listing2_1.cpp
 *
 * By Sebastian Raaphorst, 2019.
 */

#include <iostream>
#include <vector>

// Imperative average.
double average_score(const std::vector<double> &scores) {
    double total = 0;

    // Even CLion recommends using std::accumulate here instead of a loop.
    for (auto score: scores)
        total += score;

    return total / scores.size();
}

int main() {
    const std::vector<double> scores = {
            33, 45, 65, 72, 81, 93, 98
    };

    std::cout << average_score(scores) << '\n';
}