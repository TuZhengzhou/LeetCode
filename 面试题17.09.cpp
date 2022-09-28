#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int getKthMagicNumber(int k)
    {

        vector<long long> argVal = {3, 5, 7};
        vector<long long> indexs = vector<long long>(3, 1);
        vector<long long> newVal = vector<long long>(3, 0);

        vector<long long> ac = vector<long long>(k + 2, 0);
        ac[0] = 0;
        ac[1] = 1;

        long long minVal;
        for (int i = 2; i <= k; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                newVal[j] = ac[indexs[j]] * argVal[j];
            }
            minVal = *(min_element(newVal.begin(), newVal.end()));
            ac[i] = minVal;
            for (int j = 0; j < 3; j++)
            {
                if (newVal[j] == minVal)
                {
                    indexs[j]++;
                }
            }
        }

        // copy(ac.begin(), ac.end(), ostream_iterator<long long>(cout, " "));
        return ac[k];
    }
};