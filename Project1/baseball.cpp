#include <string>
#include <stdexcept>

using namespace std;

class Baseball
{
public:
    void guess(string guessNumber)
    {
        if (guessNumber.length() != 3)
        {
            throw length_error("Must be three letters");
        }

        for (char letter : guessNumber)
        {
            if ((letter < '0') || (letter > '9'))
            {
                throw invalid_argument("Must be number");
            }
        }
    }
};