# CMakeLists.txt
# By Sebastian Raaphorst, 2019.

configure_file(listing1_1.cpp listing1_1.cpp COPYONLY)
configure_file(listing1_2.cpp listing1_2.cpp COPYONLY)
configure_file(listing1_4.cpp listing1_4.cpp COPYONLY)
configure_file(listing1_5.cpp listing1_5.cpp COPYONLY)
add_executable(listing1_1 listing1_1.cpp)
add_executable(listing1_2 listing1_2.cpp)
add_executable(listing1_4 listing1_4.cpp)
add_executable(listing1_5 listing1_5.cpp)
add_executable(people people.cpp)

# Never finished compiling.
#add_executable(sieve_range sieve_range.cpp)
# Works fine.
add_executable(sieve_stl sieve_stl.cpp)
