#include <algorithm>
#include <vector>
using namespace std;
namespace Solution
{
    vector<int> findDisappearedNumbers(vector<int>& nums) 
    {
        // return if empty
        if (nums.empty())
            return vector<int>();
        
        auto cur = nums.begin();
        auto end = nums.end();
        sort(cur, end);
        vector<int> disappearedNumbers;
        int tofind = 1;
        int curnumber = *cur;

        while(cur != end)
        {
            if (curnumber > tofind)
            {
                for (; tofind < curnumber; ++tofind)
                {
                    disappearedNumbers.push_back(tofind);
                }
            }
            ++cur;
            tofind = curnumber + 1; // to find the expect number
                                    //(if the numbers are integral, the expect number should be curnumber+1)
            curnumber = *cur;
        }
        int size = nums.size();
        for (; tofind <= size; ++tofind)
            disappearedNumbers.push_back(tofind);
        return disappearedNumbers;
    }
}
