/// @file pa11.cpp
/// @author Chris Catechis
/// @date 6/20/21
/// @brief This program tests the OrderedSet.h & .cpp files.

#include "OrderedSet.h"
#include "OrderedSet.h"  // Check include guard.
#include <iostream>
#include <cctype>
#include <sstream>
#include <string>

#define CATCH_CONFIG_MAIN
#include <catch.hpp>

// constant declaration phase

/// set of unique items used to initialize a OrderedSet.
static const OrderedSet::value_type UNIQUENUMS[] = { 1, 2, 3, 4, 5, 6, 7, 8, 8, 8, 9, 10,
                                                  11, 12, 13, 14, 14, 15, 19, 20 };

/// set of duplicate items used to initialize a OrderedSet.
static const OrderedSet::value_type NUMS[] = { 1, 1, 2, 2, 5, 7, 7, 7, 8, 8, 9, 10,
                                                  11, 11, 13, 14, 14, 15, 19, 20 };

// function prototype phase
void initialize_set(OrderedSet& set, const OrderedSet::value_type list[], size_t size);
std::string::size_type count_char(const std::string& str, char ch);


// testing phase

TEST_CASE("OrderedSet::OrderedSet()"){
    OrderedSet testSet;  // OrderedSet for test case.

    REQUIRE(testSet.size() == 0);
}

TEST_CASE("OrderedSet::size()"){
    OrderedSet testSet;  // OrderedSet for test case.

    container.insert(5);
    container.insert(3);
    container.insert(4);
    container.insert(3);

    CHECK(testSet.size() == 3);

    container.insert(2);

    CHECK(testSet.size() == 4);

    testSet.clear();

    CHECK(testSet.size() == 0);
}

TEST_CASE("OrderedSet::empty()") {
    OrderedSet testSet;  // OrderedSet for test case.

    CHECK(testSet.empty() == true);

    initialize_set(set, NUMS, 10);

    CHECK(testSet.empty() == false);

    testSet.clear();
    CHECK(testSet.empty() == true);
}

TEST_CASE("OrderedSet::insert()") {
    OrderedSet testSet;  // OrderedSet for test case.

    // test 10 nums were inserted
    initialize_set(testSet, UNIQUENUMS, 10);
    CHECK(testSet.size() == 10);
    testSet.clear();  // clear for next test

    // test 20 nums were inserted
    initialize_set(set, UNQIUENUMS, 20);
    CHECK(testSet.size() == 20);
}

TEST_CASE("OrderedSet::erase()") {
    OrderedSet testSet;  // OrderedSet for test case.

    // test 1 num was erased
    initialize_set(testSet, UNIQUENUMS, 10);
    testSet.erase(1);
    CHECK(testSet.contains(1) == false);
    testSet.clear();  // clear for next test

    // test 3 unique nums were erased
    initialize_set(testSet, UNIQUENUMS, 20);
    testSet.erase(1);
    CHECK(testSet.contains(1) == false);
    testSet.erase(5);
    CHECK(testSet.contains(5) == false);
    testSet.erase(10);
    CHECK(testSet.contains(10) == false);
}

TEST_CASE("OrderedSet::clear()") {
    OrderedSet testSet;  // OrderedSet for test case.

    initialize_set(testSet, UNIQUENUMS, 15);
    testSet.clear();
    CHECK(testSet.empty() == true);
}

TEST_CASE("OrderedSet::count()") {
    OrderedSet testSet;  // OrderedSet for test case.

    initialize_set(testSet, NUMS, 15);
    CHECK(testSet.count(1) == 1);  //testSet should contains one 1.

    testSet.clear();  // clear testSet for next test.

    initialize_set(testSet, NUMS, 15);
    CHECK(testSet.count(7) == 1);  //testSet should contains one 7.
}

TEST_CASE("OrderedSet::contains()") {
    OrderedSet testSet;  // OrderedSet for test case.

    initialize_set(testSet, UNIQUENUMS, 15);

    CHECK(testSet.contains(1) == true);  //testSet should contain 1.
}

TEST_CASE("Container::write()") {
    OrderedSet testSet;  // OrderedSet for test case.
    std::ostringstream oss;
    std::string output;

    initialize_set(testSet, NUMS, 10);

    container.write(oss);
    output = oss.str();

    // tests assume unspecified order (class invariant)
    INFO("Unexpected output from function write() = " << output);
    CHECK(output.front() == '{');
    CHECK(output.back()  == '}');
    CHECK(output.size()  == 21);

    // count occurrences of item in output -- expecting 1 for each item
    for (char ch = '0'; std::isdigit(ch); ++ch) {
        INFO("when ch = " << ch);
        CHECK(count_char(output, ch) == 1);
    }

    // count the number of commas ',' in the output - expecting 9
    CHECK(count_char(output, ',') == 9);
}

// function scripting phase

/// initializes containers to hold a certain value size.
/// @param container is the container to be initialized.
/// @param list is an array of values to be inserted.
/// @param size is the amount of values to be inserted.
void initialize_set(OrderedSet& set,
                          const OrderedSet::value_type list[], size_t size) {
    for (size_t i = 0; i < size; i++) {
        set.insert(list[i]);
    }
}

/// ---------------------------------------------------------------------------
/// Counts the number of occurrences of a character within a string.
/// @param str The string to search.
/// @param ch  The target character.
/// @returns The number of times ch is found in str.
/// ---------------------------------------------------------------------------
std::string::size_type count_char(const std::string& str, char ch) {
    using std::string;

    string::size_type count = 0;

    for (string::size_type i = 0; i < str.size(); ++i) {
        if (str.at(i) == ch) {
            ++count;
        }
    }

    return count;
}