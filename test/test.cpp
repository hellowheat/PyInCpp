// Test suite for PyInCpp library - Python-like 'in' operator for C++ STL containers
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <array>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <utility>
#include <list>
#include <deque>
#include "PyInCpp_v0_9.hpp"

// Test result counters
int passed_count = 0;
int failed_count = 0;

// Macro for test assertions with error reporting
#define TEST_ASSERT(expr) \
    do { \
        if (!(expr)) { \
            std::cout << "    FAILED: " << #expr << " at " << __FILE__ << ":" << __LINE__ << std::endl; \
            throw std::runtime_error("Assertion failed"); \
        } \
    } while(0)

// Test 'in' operator with std::vector containers
void test_vector() {
    try {
        std::vector<int> nums = {1, 2, 3, 4, 5};
        TEST_ASSERT(3 in nums);
        TEST_ASSERT(!(10 in nums));

        std::vector<std::string> names = {"Alice", "Bob", "Charlie"};
        TEST_ASSERT("Bob" in names);
        TEST_ASSERT(!("David" in names));

        std::vector<double> values = {1.1, 2.2, 3.3};
        TEST_ASSERT(2.2 in values);
        TEST_ASSERT(!(4.4 in values));

        std::cout << "Testing vector... PASSED" << std::endl;
        passed_count++;
    } catch (...) {
        std::cout << "Testing vector... FAILED" << std::endl;
        failed_count++;
    }
}

// Test 'in' operator with std::list containers
void test_list() {
    try {
        std::list<int> nums = {1, 2, 3, 4, 5};
        TEST_ASSERT(3 in nums);
        TEST_ASSERT(!(10 in nums));

        std::list<std::string> names = {"Alice", "Bob", "Charlie"};
        TEST_ASSERT("Bob" in names);
        TEST_ASSERT(!("David" in names));

        std::cout << "Testing list... PASSED" << std::endl;
        passed_count++;
    } catch (...) {
        std::cout << "Testing list... FAILED" << std::endl;
        failed_count++;
    }
}

// Test 'in' operator with std::deque containers
void test_deque() {
    try {
        std::deque<int> nums = {1, 2, 3, 4, 5};
        TEST_ASSERT(3 in nums);
        TEST_ASSERT(!(10 in nums));

        std::deque<std::string> names = {"Alice", "Bob", "Charlie"};
        TEST_ASSERT("Bob" in names);
        TEST_ASSERT(!("David" in names));

        std::cout << "Testing deque... PASSED" << std::endl;
        passed_count++;
    } catch (...) {
        std::cout << "Testing deque... FAILED" << std::endl;
        failed_count++;
    }
}

// Test 'in' operator with std::array containers
void test_array() {
    try {
        std::array<int, 5> arr = {10, 20, 30, 40, 50};
        TEST_ASSERT(30 in arr);
        TEST_ASSERT(!(100 in arr));

        std::array<std::string, 3> names = {"Alice", "Bob", "Charlie"};
        TEST_ASSERT("Bob" in names);
        TEST_ASSERT(!("David" in names));

        std::cout << "Testing array... PASSED" << std::endl;
        passed_count++;
    } catch (...) {
        std::cout << "Testing array... FAILED" << std::endl;
        failed_count++;
    }
}

// Test 'in' operator with std::set containers
void test_set() {
    try {
        std::set<int> nums = {1, 2, 3, 4, 5};
        TEST_ASSERT(3 in nums);
        TEST_ASSERT(!(10 in nums));

        std::set<std::string> names = {"Alice", "Bob", "Charlie"};
        TEST_ASSERT("Bob" in names);
        TEST_ASSERT(!("David" in names));

        std::set<double> values = {1.1, 2.2, 3.3};
        TEST_ASSERT(2.2 in values);
        TEST_ASSERT(!(4.4 in values));

        std::cout << "Testing set... PASSED" << std::endl;
        passed_count++;
    } catch (...) {
        std::cout << "Testing set... FAILED" << std::endl;
        failed_count++;
    }
}

// Test 'in' operator with std::multiset containers
void test_multiset() {
    try {
        std::multiset<int> nums = {1, 2, 2, 3, 4, 5};
        TEST_ASSERT(2 in nums);
        TEST_ASSERT(!(10 in nums));

        std::multiset<std::string> names = {"Alice", "Bob", "Bob", "Charlie"};
        TEST_ASSERT("Bob" in names);
        TEST_ASSERT(!("David" in names));

        std::cout << "Testing multiset... PASSED" << std::endl;
        passed_count++;
    } catch (...) {
        std::cout << "Testing multiset... FAILED" << std::endl;
        failed_count++;
    }
}

// Test 'in' operator with std::unordered_set containers
void test_unordered_set() {
    try {
        std::unordered_set<int> nums = {1, 2, 3, 4, 5};
        TEST_ASSERT(3 in nums);
        TEST_ASSERT(!(10 in nums));

        std::unordered_set<std::string> names = {"Alice", "Bob", "Charlie"};
        TEST_ASSERT("Bob" in names);
        TEST_ASSERT(!("David" in names));

        std::cout << "Testing unordered_set... PASSED" << std::endl;
        passed_count++;
    } catch (...) {
        std::cout << "Testing unordered_set... FAILED" << std::endl;
        failed_count++;
    }
}

// Test 'in' operator with std::unordered_multiset containers
void test_unordered_multiset() {
    try {
        std::unordered_multiset<int> nums = {1, 2, 2, 3, 4, 5};
        TEST_ASSERT(2 in nums);
        TEST_ASSERT(!(10 in nums));

        std::unordered_multiset<std::string> names = {"Alice", "Bob", "Bob", "Charlie"};
        TEST_ASSERT("Bob" in names);
        TEST_ASSERT(!("David" in names));

        std::cout << "Testing unordered_multiset... PASSED" << std::endl;
        passed_count++;
    } catch (...) {
        std::cout << "Testing unordered_multiset... FAILED" << std::endl;
        failed_count++;
    }
}

// Test 'in' operator with std::map containers (key and key-value pair lookup)
void test_map() {
    try {
        std::map<std::string, int> scores = {
            {"Alice", 95},
            {"Bob", 87},
            {"Charlie", 92}
        };
        TEST_ASSERT("Alice" in scores);
        TEST_ASSERT(!("David" in scores));

        TEST_ASSERT(std::make_pair("Bob", 87) in scores);
        TEST_ASSERT(!(std::make_pair("Alice", 90) in scores));

        std::map<int, std::string> ids = {
            {1, "Alice"},
            {2, "Bob"},
            {3, "Charlie"}
        };
        TEST_ASSERT(2 in ids);
        TEST_ASSERT(!(4 in ids));

        TEST_ASSERT(std::make_pair(2, "Bob") in ids);
        TEST_ASSERT(!(std::make_pair(1, "Bob") in ids));

        std::map<std::string, char> grades = {
            {"Alice", 'A'},
            {"Bob", 'B'},
            {"Charlie", 'C'}
        };
        TEST_ASSERT("Alice" in grades);
        TEST_ASSERT(!("David" in grades));

        TEST_ASSERT(std::make_pair("Bob", 'B') in grades);
        TEST_ASSERT(!(std::make_pair("Alice", 'B') in grades));

        std::cout << "Testing map... PASSED" << std::endl;
        passed_count++;
    } catch (...) {
        std::cout << "Testing map... FAILED" << std::endl;
        failed_count++;
    }
}

// Test 'in' operator with std::multimap containers
void test_multimap() {
    try {
        std::multimap<std::string, int> scores = {
            {"Alice", 95},
            {"Bob", 87},
            {"Bob", 90},
            {"Charlie", 92}
        };
        TEST_ASSERT("Bob" in scores);
        TEST_ASSERT(!("David" in scores));

        TEST_ASSERT(std::make_pair("Bob", 87) in scores);
        TEST_ASSERT(!(std::make_pair("Alice", 90) in scores));

        std::cout << "Testing multimap... PASSED" << std::endl;
        passed_count++;
    } catch (...) {
        std::cout << "Testing multimap... FAILED" << std::endl;
        failed_count++;
    }
}

// Test 'in' operator with std::unordered_map containers
void test_unordered_map() {
    try {
        std::unordered_map<std::string, int> scores = {
            {"Alice", 95},
            {"Bob", 87},
            {"Charlie", 92}
        };
        TEST_ASSERT("Alice" in scores);
        TEST_ASSERT(!("David" in scores));

        TEST_ASSERT(std::make_pair("Bob", 87) in scores);
        TEST_ASSERT(!(std::make_pair("Alice", 90) in scores));

        std::unordered_map<int, std::string> ids = {
            {1, "Alice"},
            {2, "Bob"},
            {3, "Charlie"}
        };
        TEST_ASSERT(2 in ids);
        TEST_ASSERT(!(4 in ids));

        std::cout << "Testing unordered_map... PASSED" << std::endl;
        passed_count++;
    } catch (...) {
        std::cout << "Testing unordered_map... FAILED" << std::endl;
        failed_count++;
    }
}

// Test 'in' operator with std::unordered_multimap containers
void test_unordered_multimap() {
    try {
        std::unordered_multimap<std::string, int> scores = {
            {"Alice", 95},
            {"Bob", 87},
            {"Bob", 90},
            {"Charlie", 92}
        };
        TEST_ASSERT("Bob" in scores);
        TEST_ASSERT(!("David" in scores));

        TEST_ASSERT(std::make_pair("Bob", 87) in scores);
        TEST_ASSERT(!(std::make_pair("Alice", 90) in scores));

        std::cout << "Testing unordered_multimap... PASSED" << std::endl;
        passed_count++;
    } catch (...) {
        std::cout << "Testing unordered_multimap... FAILED" << std::endl;
        failed_count++;
    }
}

// Main function - runs all test cases and reports results
int main() {
    std::cout << "========================================" << std::endl;
    std::cout << "PyInCpp Test Suite" << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << std::endl;

    test_vector();
    test_list();
    test_deque();
    test_array();
    test_set();
    test_multiset();
    test_unordered_set();
    test_unordered_multiset();
    test_map();
    test_multimap();
    test_unordered_map();
    test_unordered_multimap();

    std::cout << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << "Test Summary" << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << "Passed: " << passed_count << std::endl;
    std::cout << "Failed: " << failed_count << std::endl;
    std::cout << "Total:  " << (passed_count + failed_count) << std::endl;
    std::cout << "========================================" << std::endl;

    return failed_count > 0 ? 1 : 0;
}
