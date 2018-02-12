#include <algorithm>
#include <vector>
namespace Solution
{
    int singleNumber(std::vector<int>& nums) 
    {        
        size_t size = nums.size();
        int result = 0;
        for (int i = 0; i < size; ++i)
        {
            result ^= nums[i];
        }
        return result;
    }
}
