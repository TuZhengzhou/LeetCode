#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        return (nums[nums.size()-1]-1)* (nums[nums.size()-2]-1);
    }
};

#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int i, j, size, i_val, j_val;   // i 和 j 分别表示最大值和次大值的下标
        i = nums[0] > nums[1] ? 0: 1;
        j = 1-i;
        i_val = nums[i];
        j_val = nums[j];

        size = nums.size();
        for( auto tmp = 2; tmp < size; tmp++ ){
            if( nums[tmp] >= i_val ){
                j = i;
                i = tmp;
                i_val = nums[i];
                j_val = nums[j];
            }else if( nums[tmp] >= j_val ){
                j = tmp;
                j_val = nums[j];
            }
        }
        return (nums[i]-1)*(nums[j]-1);
    }
};