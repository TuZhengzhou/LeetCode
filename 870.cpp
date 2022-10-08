#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;
class Solution
{
public:
    // vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {

    //     unordered_map<int, vector<int>> my_map;
    //     sort(nums1.begin(), nums1.end());

    //     vector<int> sorted_nums2;
    //     for( auto item: nums2 ){
    //         sorted_nums2.push_back(item);
    //     }
    //     sort(sorted_nums2.begin(), sorted_nums2.end());

    //     unordered_map<int, int> counts;
    //     int n = nums2.size();
    //     int low = 0, high = n-1;
    //     for(int i = n-1; i >= 0; i--){
    //         if(sorted_nums2[i] < nums1[high]){
    //             my_map[sorted_nums2[i]].push_back(nums1[high--]);
    //         }else{
    //             my_map[sorted_nums2[i]].push_back(nums1[low++]);
    //         }
    //         counts[sorted_nums2[i]] = 0;
    //     }

    //     // for(auto [key, val]: my_map){
    //     //     cout << "key = " << key << endl;
    //     //     copy(val.begin(), val.end(), ostream_iterator<int>(cout, " "));
    //     //     cout << endl;
    //     // }

    //     int key;
    //     for(int i = 0; i < n; i++){
    //         key = nums2[i];
    //         nums1[i] = my_map[key][counts[key]];
    //         counts[nums2[i]] += 1;
    //     }

    //     return nums1;
    // }

    vector<int> advantageCount(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        vector<int> idx1(n), idx2(n);
        iota(idx1.begin(), idx1.end(), 0);
        iota(idx2.begin(), idx2.end(), 0);
        sort(idx1.begin(), idx1.end(), [&](int i, int j)
             { return nums1[i] < nums1[j]; });
        sort(idx2.begin(), idx2.end(), [&](int i, int j)
             { return nums2[i] < nums2[j]; });

        vector<int> ans(n);
        int left = 0, right = n - 1;
        for (int i = 0; i < n; ++i)
        {
            if (nums1[idx1[i]] > nums2[idx2[left]])
            {
                ans[idx2[left]] = nums1[idx1[i]];
                ++left;
            }
            else
            {
                ans[idx2[right]] = nums1[idx1[i]];
                --right;
            }
        }
        return ans;
    }
}; // vector<int> ans;
   // for()