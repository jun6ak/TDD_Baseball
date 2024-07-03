#include "pch.h"
#include "../Project1/baseball.cpp"
#include <string>
#include <stdexcept>

using namespace std;

TEST(TestCaseName, ThrowExceptionWhenInputLengthUnmatched) {
    Baseball baseball;
    EXPECT_THROW(baseball.guess(string("12")), length_error);
}