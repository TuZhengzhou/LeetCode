#include <vector>
using namespace std;
class Solution
{
public:
    int maxAscendingSum(vector<int> &nums)
    {
        int pre = 0, sum = 0;
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] > pre)
            {
                sum += nums[i];
                pre = nums[i];
            }
            else
            {
                ans = sum > ans ? sum : ans;
                sum = nums[i];
                pre = nums[i];
            }
        }
        ans = sum > ans ? sum : ans;
        return ans;
    }
};

class Solution
{
public:
    int maxAscendingSum(vector<int> &nums)
    {
        int res = 0;
        int l = 0;
        while (l < nums.size())
        {
            int cursum = nums[l++];
            while (l < nums.size() && nums[l] > nums[l - 1])
            {
                cursum += nums[l++];
            }
            res = max(res, cursum);
        }
        return res;
    }
};

// 作者：LeetCode-Solution
// 链接：https://leetcode.cn/problems/maximum-ascending-subarray-sum/solution/zui-da-sheng-xu-zi-shu-zu-he-by-leetcode-0q6v/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。