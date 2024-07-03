#include "pch.h"
#include "../Project1/baseball.cpp"
#include <string>
#include <stdexcept>

using namespace std;

TEST(TestBaseball, ThrowExceptionWhenInputLengthUnmatched) {
    Baseball baseball;
    EXPECT_THROW(baseball.guess(string("12")), length_error);
}

TEST(TestBaseball, ThrowExceptionWhenInvalidChar) {
    Baseball baseball;
    EXPECT_THROW(baseball.guess(string("12s")), invalid_argument);
}