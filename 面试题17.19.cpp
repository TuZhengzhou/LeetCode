/*
给定一个数组，包含从 1 到 N 所有的整数，但其中缺了两个数字。你能在 O(N) 时间内只用 O(1) 的空间找到它们吗？

以任意顺序返回这两个数字均可
*/
#include <vector>

using namespace std;

// 一个数学方法
class Solution
{
public:
    vector<int> missingTwo(vector<int> &nums)
    {
        long long n, full_n, full_sum_1, full_sum_2, sum_1, sum_2;

        n = size(nums);
        full_n = n + 2;
        full_sum_1 = (full_n + 1) * full_n / 2;                    // 累和公式
        full_sum_2 = full_n * (full_n + 1) * (2 * full_n + 1) / 6; // 平方和公式

        sum_1 = 0;
        sum_2 = 0;
        for (int i = 0; i < n; i++)
            sum_1 += nums[i];
        for (int i = 0; i < n; i++)
            sum_2 += nums[i] * nums[i];

        long long gap1, gap2;
        gap1 = full_sum_1 - sum_1; // a+b
        gap2 = full_sum_2 - sum_2; // a^2+b^2

        long mult = gap1 * gap1 - gap2; // 2ab
        long long add_square, sub_square;
        add_square = gap2 + mult; // (a+b)^2
        sub_square = gap2 - mult; // (a-b)^2

        long long add, sub;
        add = sqrt(add_square); // a+b
        sub = sqrt(sub_square); // a-b

        vector<int> ret(2);
        ret[0] = (add + sub) / 2; // a
        ret[1] = (add - sub) / 2; // b
        // copy(ret.begin(), ret.end(), ostream_iterator<int>(cout, " "));
        return ret;
    }
};