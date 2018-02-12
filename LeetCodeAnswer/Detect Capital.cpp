#include <cctype>
#include <string>
using namespace std;
namespace Solution
{
    bool detectCapitalUse(string word) 
    {
        auto cur = word.begin();
        auto end = word.end();
        char c;
        // find first letter in the word
        while (cur != end)
        {
            c = *cur;
            if (islower(c) || isupper(c))
                break;
            ++cur;
        }
        if (cur == end)
            return true;
        
        bool startCapital = isupper(c);        
        if (startCapital)
        {
            ++cur;
            // find second letter
            while (cur != end)
            {
                c = *cur;
                if (islower(c) || isupper(c))
                    break;
                ++cur;
            }
            // if only one letter and it is uppercase
            if (cur == end)
                return true;
            ++cur;
            startCapital = isupper(c);
            if (startCapital)
            {
                // all the letter should be Capital
                while (cur != end)
                {
                    c = *cur;
                    if (islower(c))
                        return false;
                    ++cur;
                }
            }
            else 
            {
                // all the rest letter should be lowercase
                while (cur != end)
                {
                    c = *cur;
                    if (isupper(c))
                        return false;
                    ++cur;
                }
            }
        }
        else
        {
            ++cur;
            while(cur != end)
            {
                c = *cur;
                if (isupper(c))
                    return false;
                ++cur;
            }
        }
        return true;
    }
}
