#include <string>
#include <stdexcept>

using namespace std;

struct GuessResult
{
    bool solved;
    int strikes;
    int balls;
};

class Baseball
{
public:
    Baseball(const string& question) : question(question)
    { }

    void setQuestion(const string& newQuestion)
    {
        assertIncorrectArgument(newQuestion);

        question = newQuestion;
    }

    GuessResult guess(const string guessNumber)
    {
        assertIncorrectArgument(guessNumber);

        if (true == isCorrectAnswer(guessNumber))
        {
            return { true, 3, 0 };
        }

        return { false, getStrikes(guessNumber), getBalls(guessNumber) };
    }

private:
    string question;

    int getStrikes(const std::string& guessNumber)
    {
        int strikes = 0;
        for (int i = 0; i < 3; i++)
        {
            if (guessNumber[i] != question[i]) continue;

            strikes++;
        }
        return strikes;
    }

    int getBalls(const std::string& guessNumber)
    {
        int balls = 0;

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (i == j) continue;
                if (guessNumber[i] != question[j]) continue;
                balls++;
            }
        }

        return balls;
    }

    void assertIncorrectArgument(const std::string& guessNumber)
    {
        if (guessNumber.length() != 3)
        {
            throw length_error("Must be three letters");
        }

        for (char letter : guessNumber)
        {
            if (('0' <= letter) && (letter <= '9')) continue;

            throw invalid_argument("Must be number");
        }

        if (true == isDuplicatedNumber(guessNumber))
        {
            throw invalid_argument("Must not have the same number");
        }
    }

    bool isDuplicatedNumber(const std::string& guessNumber)
    {
        return (guessNumber[0] == guessNumber[1])
            || (guessNumber[0] == guessNumber[2])
            || (guessNumber[1] == guessNumber[2]);
    }

    bool isCorrectAnswer(const std::string& guessNumber)
    {
        return guessNumber == question;
    }
};