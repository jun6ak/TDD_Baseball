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

    GuessResult guess(string guessNumber)
    {
        assertIncorrectArgument(guessNumber);

        if (guessNumber == question)
        {
            return { true, 3, 0 };
        }

        if ((guessNumber[0] == question[0])
            && (guessNumber[1] == question[1])
            && (guessNumber[2] != question[2]))
        {
            return { false, 2, 0 };
        }

        if ((guessNumber[0] != question[0])
            && (guessNumber[1] == question[1])
            && (guessNumber[2] == question[2]))
        {
            return { false, 2, 0 };
        }

        return { false, 0, 0 };
    }

private:
    string question;

    void assertIncorrectArgument(std::string& guessNumber)
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

    bool isDuplicatedNumber(std::string& guessNumber)
    {
        return (guessNumber[0] == guessNumber[1])
            || (guessNumber[0] == guessNumber[2])
            || (guessNumber[1] == guessNumber[2]);
    }
};