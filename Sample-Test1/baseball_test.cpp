#include "pch.h"
#include "../Project1/baseball.cpp"
#include <string>
#include <stdexcept>

using namespace std;

class TestBaseballFixture : public testing::Test
{
protected:
    Baseball baseball{ "123" };

    void assertGuessInvalidNumber(string guessNumber)
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

    void assertSetInvalidQuestion(string guessNumber)
    {
        try
        {
            baseball.setQuestion(guessNumber);
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

TEST_F(TestBaseballFixture, ThrowExceptionWhenInvalidCase_guess) {
    assertGuessInvalidNumber(string("12"));
    assertGuessInvalidNumber(string("12s"));
    assertGuessInvalidNumber(string("121"));
}

TEST_F(TestBaseballFixture, ThrowExceptionWhenInvalidCase_setquestion) {
    assertSetInvalidQuestion(string("12"));
    assertSetInvalidQuestion(string("12s"));
    assertSetInvalidQuestion(string("121"));
}

TEST_F(TestBaseballFixture, ReturnSolvedResultIfMatchedNumber) {
    GuessResult result = baseball.guess("123");

    checkResult(result, true, 3, 0);
}

TEST_F(TestBaseballFixture, ReturnSolvedResult1_2S0B) {
    GuessResult result = baseball.guess("124");

    checkResult(result, false, 2, 0);
}

TEST_F(TestBaseballFixture, ReturnSolvedResult2_2S0B) {
    GuessResult result = baseball.guess("423");

    checkResult(result, false, 2, 0);
}

TEST_F(TestBaseballFixture, ReturnSolvedResult_1S2B) {
    GuessResult result = baseball.guess("321");

    checkResult(result, false, 1, 2);
}

TEST_F(TestBaseballFixture, ReturnSolvedResult_0S1B) {
    GuessResult result = baseball.guess("279");

    checkResult(result, false, 0, 1);
}

TEST_F(TestBaseballFixture, ReturnSolvedResult_0S3B) {
    GuessResult result = baseball.guess("312");

    checkResult(result, false, 0, 3);
}

TEST_F(TestBaseballFixture, ReturnSolvedResult2_0S3B) {
    baseball.setQuestion("312");

    GuessResult result = baseball.guess("123");

    checkResult(result, false, 0, 3);
}

TEST_F(TestBaseballFixture, ReturnSolvedResult_0S0B) {
    baseball.setQuestion("456");

    GuessResult result = baseball.guess("129");

    checkResult(result, false, 0, 0);
}
