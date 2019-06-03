/**
 * prelude.cpp
 *
 * By Sebastian Raaphorst, 2019.
 */

#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>


// Compiler deduces return type.
int answer = 42;
auto ask1() { return answer; } // returns int
const auto &ask2() { return answer; } // returns consst int&

// Return types must obviously be consistent.
// This will not compile.
//auto fail_func(bool flag) {
//    if (flag) return 3;
//    else return std::string{"hello"};
//}

// After the return type is deduced, it can be used in the rest of the function.
// This allows recursive auto functions.
auto factorial(unsigned long n) {
    if (n == 0)
        return 1UL;
    else
        return n * factorial(n-1);
}

// This, however, won't work, as the compiler needs to determine the return type first:
// Complain: factorial2 with deduced return type cannot be used before it is defined.
//auto factorial2(unsigned long n) {
//    if (n > 0)
//        return n * factorial2(n-1);
//    else
//        return 0UL;
//}

// ***** DECLTYPE *****
// Instead of using auto, which uses the template argument type deduction rules, you can use
// decltype(auto), which uses the declytype rules:
decltype(auto) ask3() { return answer; } // returns int
decltype(auto) ask4() { return (answer); } // returns int&, i.e. declype((int)).
decltype(auto) ask5() { return 42 + answer; } // returns an int, i.e. decltype(42 + answer)

// *** PERFECT FORWARDING / FORWARDING REFERENCES / UNIVERSAL REFERENCES ***
template<typename Object, typename Function>
decltype(auto) call_function_on_object1(Object&& o, Function function) {
    return function(std::forward<Object>(o));
}

// You don't know anythong about Function, and how it expects its argument.
// You can pass by value:
template<typename Object, typename Function>
decltype(auto) call_function_on_object2(Object o, Function function) {
    return function(o);
}

// You can pass by reference.
// If non-const, this is not a pure function as changes could be made to o.
// Caller won't be able to invoke call_function_on_object3/4 on a constant object or temporary value.
// Perhaps intent IS to change o, in which case const ref doesn't work.
// Thus neither passing as a reference nor const reference is right.
template<typename Object, typename Function>
decltype(auto) call_function_on_object4(Object &o, Function function) {
    return function(o);
}
template<typename Object, typename Function>
decltype(auto) call_function_on_object5(const Object &o, Function function) {
    return function(o);
}

// This is the problem solved in C++11 by forwarding references (aka universal references).
// Otherwise you end up with an exponential number of methods based on the number of parameters.
// In this code, the fwd argument is a forwarding reference to type T.
// On othe other hand, value is just a regular r-value reference.
template<typename T>
void forwarding_func(T&& t, int&& value) {
    // do nothing
}

// The forwarding (universal) reference allows you to accept both const and non-const objects,
// and temporary objects. Now you only need to pass that argument, and pass it in the same value
// category you received it, which is what std::forward does.


// *** FUNCTION POOINTERS ***
// Inherited from C.
// Runtime polymorphism achieved by changing what function is pointed to, thus changing behaviour.
// Also called FUCTION OBJECTS because they can be called like ordinary functions.
// All types that can be implicitly converted to a function pointer are also function objects.
// You should prefer PROPER function objects (see below).
int ask6() { return 42; }

// Look at how ghastly the non-decltype version is.
typedef int (*ugly_function_ptr)(void);
typedef decltype(ask6)* function_ptr;

// This works also if parameters are taken.
bool ask7(int value, int check) { return value > check; }
typedef bool (*ugly_function_ptr2)(int, int);
typedef decltype(ask7)* function_ptr2;

// CASTING OPERATOR.
struct convertible_to_function_ptr1 {
    // Casting operator can only return a pointer to a function.
    operator function_ptr() const {
        return ask6;
    }
};

struct convertible_to_function_ptr2 {
    operator ugly_function_ptr() const {
        return ask6;
    }
};

// Easier example of a casting operator:
struct Person {
    const std::string first_name;
    const std::string last_name;
    const unsigned short age;

    // Automatically converts a person to a std::string.
    operator std::string() {
        return first_name + " " + last_name;
    }
};


// *** CALL OPERATOR OVERLOADING ***
// Much nicer than implicit conversion to function ptr.
// Can also have own state, mutable or not.
struct summer {
    int operator()(int arg1, int arg2) const {
        return arg1 + arg2;
    }
};

// To count people older than 42. Of course, this isn't scaleable because you'd have to create
// a version for each age of interest.
bool older_than_42(const Person &p) {
    return p.age > 42;
}

// Solution: immutable state counter.
// Called FUNCTORS, but not equivalent to category theory functors, so we call them function objects.
struct age_filter {
    const int min_age = 0;
    const int max_age = 100;

    bool operator()(const Person &p) const {
        return p.age >= min_age && p.age <= max_age;
    }
};

// GENERIC CALL OPERATOR OVERLOADING.
// Now duck typing and SFINAE: you can use this for people, pets, cars, etc.
// This is unnecessary: the template could be part of the operator. See listing3_1.cpp.
template<typename T>
struct generic_age_filter {
    const int min_age;
    const int max_age;

    bool operator()(const T &t) const {
        return t.age > min_age && t.age < max_age;
    }
};

int main() {
    // see above: returns int& so we can change answer
    ask4() = 9;
    std::cout << answer << '\n';

    int &&i = ask5();
    std::cout << i << '\n';



    auto ask_ptr = &ask6;
    std::cout << ask_ptr() << '\n';

    auto &ask_ref = ask6;
    std::cout << ask_ref() << '\n';

    // Cannot mark explicit or this does not work.
    convertible_to_function_ptr1 ask_wrapper1;
    std::cout << ask_wrapper1() << '\n';
    convertible_to_function_ptr1 ask_wrapper2;
    std::cout << ask_wrapper2() << '\n';

    Person p{"Sebastian", "Raaphorst", 41};
    std::string name = p;
    std::cout << name << '\n';


    const std::vector<Person> people{
            {"Sebastian", "Raaphorst", 41},
            {"Jeffery", "Raaphorst", 38},
            {"Stupid", "Moron", 54},
            {"Cry", "Baby", 100},
            {"Smelly", "Cat", 33}
    };

    auto old = std::count_if(std::cbegin(people), std::cend(people), older_than_42);
    std::cout << old << '\n';

    // Create an age filter function object for count_if.
    auto middle_age = std::count_if(std::cbegin(people), std::cend(people), age_filter{30, 50});
    std::cout << middle_age << '\n';

    auto less_than_a_century = std::count_if(std::cbegin(people), std::cend(people), generic_age_filter<Person>{0, 99});
    std::cout << less_than_a_century << '\n';
}
