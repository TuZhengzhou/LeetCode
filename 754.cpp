#include <algorithm>
using namespace std;

// https://leetcode.cn/problems/reach-a-number/solution/

class Solution
{
public:
    int reachAbsNumber(unsigned int target)
    {
        int idx = 0;
        int sum = 0;
        while (sum < target)
        {
            idx += 1;
            sum += idx;
        }
        if ((sum - target) % 2)
            // return idx + 1 + idx%2;
            if ((idx + 1) % 2)
                return idx + 1;
            else
                return idx + 2;
        else
            return idx;
    }
    int reachNumber(int target)
    {
        return reachAbsNumber(abs(target));
    }
};