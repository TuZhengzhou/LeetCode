#include <vector>
#include <string>
using namespace std;
class Solution
{
public:
    bool CheckPermutation(string s1, string s2)
    {
        vector<int> ac = vector<int>(123, 0);
        for (char c : s1)
            ac[c] += 1;
        for (char c : s2)
        {
            ac[c] -= 1;
            if (ac[c] < 0)
                return false;
        }
        for (int n : ac)
            if (n)
                return false;
        return true;
    }
};