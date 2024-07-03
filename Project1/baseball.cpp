#include <string>
#include <stdexcept>

using namespace std;

class Baseball
{
public:
    void guess(string str)
    {
        throw length_error("Must be three letters");
    }
};