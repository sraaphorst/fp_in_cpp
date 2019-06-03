#include <iostream>
#include <numeric>
#include <algorithm>
#include <array>
#include <type_traits>

#include <range/v3/all.hpp>
#include <range/v3/view/all.hpp>
#include <range/v3/view/iota.hpp>
using namespace ranges;

namespace impl {
    template<typename R>
    std::vector<int> sieve_aux(R &&range, std::vector<int> primes) {
        std::cout << ranges::view::all(range) << '\n';
        if (range.empty())
            return primes;

        auto head = front(range);
        std::cout << "HEAD: " << head << '\n';
        primes.emplace_back(head);

        auto range2 = range | view::remove_if([head](const auto v) { return v % head == 0; });
        std::cout << ranges::view::all(range2) << '\n';
        return sieve_aux(range2, primes);

//        if (range2.empty())
//            return primes;
//        auto head2 = front(range2);
//        std::cout << "HEAD: " << head2 << '\n';
//        primes.emplace_back(head2);
//        auto range3 = range2 | view::remove_if([head2](const auto v) { return v % head2 == 0; });
//        std::cout << ranges::view::all(range3) << '\n';
//
//        if (range3.empty())
//            return primes;
//        auto head3 = front(range3);
//        std::cout << "HEAD: " << head3 << '\n';
//        primes.emplace_back(head3);
//        auto range4 = range3 | view::remove_if([head3](const auto v) { return v % head3 == 0; });
//        std::cout << ranges::view::all(range4) << '\n';
//
//        if (range4.empty())
//            return primes;
//        auto head4 = front(range4);
//        std::cout << "HEAD: " << head4 << '\n';
//        primes.emplace_back(head4);
//        auto range5 = range4 | view::remove_if([head4](const auto v) { return v % head4 == 0; });
//        std::cout << ranges::view::all(range5) << '\n';
//
//        return primes;
    }
}

std::vector<int> sieve(int num) {
    return impl::sieve_aux(view::iota(2, num), {});
}

int main() {
    auto primes = sieve(10);
}