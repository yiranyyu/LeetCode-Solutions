#include <vector>
using namespace std;
namespace Solution
{
    void moveZeroes(vector<int>& nums) 
    {
        auto begin = nums.begin();
        auto cur = begin;
        auto end = nums.end();
        // find first zero
        while(cur != end )
        {
            if (*cur == 0)
                break;
            ++cur;
        }
        // do not have to move any element
        auto tail = begin + (nums.size() - 1);
        if (cur == end || cur == tail)
            return;
        
        // begin swap
        int gap = 1;
        auto next = cur + gap;
        while(cur != tail && next != end)
        {
            if (*next != 0)
            {
                swap(*cur, *next);
                ++cur;
            }
            else
            {
                ++gap;
            }
            next = cur + gap;
        }
    }
}
