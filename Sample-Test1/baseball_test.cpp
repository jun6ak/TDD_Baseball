#include "pch.h"
#include "../Project1/baseball.cpp"
#include <string>
#include <stdexcept>

using namespace std;

class TestBaseballFixture : public testing::Test
{
protected:
    Baseball baseball;
    void assertIncorrectArgument(string guessNumber)
    {
        try
        {
            baseball.guess(guessNumber);
            FAIL();
        }
        catch (exception& e)
        {
            ; // do nothing
        }
    }
};

TEST_F(TestBaseballFixture, ThrowExceptionWhenInvalidCase) {
    assertIncorrectArgument(string("12"));
    assertIncorrectArgument(string("12s"));
}
