#include <string>
using namespace std;
namespace Solution
{
    char findTheDifference(string s, string t) 
    {
        size_t length = s.size();
        char r = t[length];
        size_t i = 0;
        for (; i < length; ++i)
        {
            r ^= s[i];
            r ^= t[i];
        }
        return r;
    }
}
