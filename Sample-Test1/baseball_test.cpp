#include "pch.h"
#include "../Project1/baseball.cpp"
#include <string>
#include <stdexcept>

using namespace std;

class TestBaseballFixture : public testing::Test
{
protected:
    Baseball baseball{ "123" };
    void assertIncorrectArgument(string guessNumber)
    {
        try
        {
            baseball.guess(guessNumber);
            FAIL();
        }
        catch (exception& e)
        {
            ; // PASS
        }
    }

    void checkResult(GuessResult result, bool solved, int strikes, int balls)
    {
        EXPECT_EQ(result.solved, solved);
        EXPECT_EQ(result.strikes, strikes);
        EXPECT_EQ(result.balls, balls);
    }
};

TEST_F(TestBaseballFixture, ThrowExceptionWhenInvalidCase) {
    assertIncorrectArgument(string("12"));
    assertIncorrectArgument(string("12s"));
    assertIncorrectArgument(string("121"));
}

TEST_F(TestBaseballFixture, ReturnSolvedResultIfMatchedNumber) {
    Baseball game{ "123" };
    GuessResult result = game.guess("123");

    checkResult(result, true, 3, 0);
}

TEST_F(TestBaseballFixture, ReturnSolvedResult1_2S0B) {
    Baseball game{ "123" };
    GuessResult result = game.guess("124");

    checkResult(result, false, 2, 0);
}

TEST_F(TestBaseballFixture, ReturnSolvedResult2_2S0B) {
    Baseball game{ "123" };
    GuessResult result = game.guess("423");

    checkResult(result, false, 2, 0);
}
