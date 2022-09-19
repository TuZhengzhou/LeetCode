#include<vector>
#include<map>
#include<unordered_map>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        /*
        // 数组实现
        vector<int> ac = vector<int>(201, 0);
        for( int i = 0; i < nums.size(); i++ ){
            ac[nums[i]+100] += 1;
        }

        // copy(ac.begin(), ac.end(), ostream_iterator<int>(cout, " "));
        sort(nums.begin(), nums.end(), [& ac](int& a, int& b){
            return ac[a+100] < ac[b+100] || (ac[a+100]==ac[b+100] && a > b);
        });
        */

        unordered_map<int,int> ac;  // unordered_map 实现
        // map<int,int> ac;         // map 实现
        for( int i = 0; i < nums.size(); i++ ){
            ac[nums[i]] += 1;
        }

        // copy(ac.begin(), ac.end(), ostream_iterator<int>(cout, " "));
        sort(nums.begin(), nums.end(), [& ac](int& a, int& b){
            return ac[a] < ac[b] || (ac[a]==ac[b] && a > b);
        });

        // copy(nums.begin(), nums.end(), ostream_iterator<int>(cout, " "));
        return nums;
    }
};