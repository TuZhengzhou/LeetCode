#include<vector>
using namespace std;
class Solution {
public:
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        int groupsSize = groups.size();
        int numsSize = nums.size();
        int groupIdx = 0, numIdx = 0;

        while(numIdx < numsSize && groupIdx < groupsSize){
            // 如果nums[numIdx]与groups[groupIdx]的第一个数都不匹配，那继续看nums数组的下一个数
            while(numIdx < numsSize && nums[numIdx] != groups[groupIdx][0]){
                numIdx++;
            }
            if(numIdx < numsSize){
                // 尝试匹配，如果匹配成功，i将会与 groups[groupIdx].size() 相等
                int i = 1;
                for(; i < groups[groupIdx].size() && nums[numIdx+i]==groups[groupIdx][i]; i++);

                // 匹配成功或失败时需要做的改动
                if(i == groups[groupIdx].size()){
                    numIdx += i;
                    groupIdx += 1;
                }else{
                    numIdx += 1;
                }
            }
        }

        // while(numIdx < numsSize && groupIdx < groupsSize){
        //     if(nums[numIdx] == groups[groupIdx][0]){
        //         int i;
        //         for(i = 1; i < groups[groupIdx].size() && nums[numIdx+i]==groups[groupIdx][i]; i++);
        //         if(i == groups[groupIdx].size()){
        //             numIdx += i;
        //             groupIdx += 1;
        //         }else{
        //             numIdx += 1;
        //         }
        //     }
        //     else
        //         numIdx += 1;
        // }
        return groupIdx == groupsSize;
    }
};