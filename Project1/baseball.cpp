#include <string>
#include <stdexcept>

using namespace std;

class Baseball
{
public:
    void guess(string guessNumber)
    {
        assertIncorrectArgument(guessNumber);
    }

private:
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