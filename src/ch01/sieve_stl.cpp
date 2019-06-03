/**
 * wtf2.cpp
 *
 * By Sebastian Raaphorst, 2019.
 */

#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>

#include <chrono>
using namespace std::chrono;

namespace impl {
    template<typename Iter>
    std::vector<int> sieve_aux(Iter begin, Iter end, std::vector<int> primes) {
        if (begin == end)
            return primes;

        auto head = *begin;
        primes.emplace_back(head);

        // These two strategies are both pretty much identical in terms of time.
        std::vector<int> out;
        std::remove_copy_if(begin, end, std::back_insert_iterator(out), [head](const auto v) { return v % head == 0; });
        //std::copy_if(begin, end, std::back_insert_iterator(out), [head](const auto v) { return v % head != 0; });
        return sieve_aux(std::begin(out), std::end(out), primes);
    }
}

std::vector<int> sieve(int maxnum) {
    std::vector<int> a{};
    a.resize(maxnum - 1);
    std::iota(std::begin(a), std::end(a), 2);
    return impl::sieve_aux(std::begin(a), std::end(a), {});
}

int main() {
    //high_resolution_clock::time_point t1 = high_resolution_clock::now();
    //for (int i=0; i < 5; ++i)
    auto p = sieve(100000);
    //high_resolution_clock::time_point t2 = high_resolution_clock::now();

    //auto duration = duration_cast<microseconds>( t2 - t1 ).count();
}