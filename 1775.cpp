#include<vector>
#include<map>
using namespace std;
// class Solution {
// public:
//     int minOperations(vector<int>& nums1, vector<int>& nums2) {
//         if(nums1.size() > 6*nums2.size() || nums2.size() > 6*nums1.size())
//             return -1;
//         map<int, int> oneAdd = {{1,0}, {2,0}, {3,0}, {4,0}, {5,0}};
//         map<int, int> oneSub = {{1,0}, {2,0}, {3,0}, {4,0}, {5,0}};
//         // for( auto i: oneAdd ){
//         //     cout << i.first << ", " << i.second << endl;
//         // }
//         int n1 = nums1.size(), n2 = nums2.size();
//         int sum1 = 0, sum2 = 0;
//         for(int idx = 0; idx < n1; idx++){
//             oneAdd[6-nums1[idx]] += 1;
//             oneSub[nums1[idx]-1] += 1;
//             sum1 += nums1[idx];
//         }
//         for(int idx = 0; idx < n2; idx++){
//             oneSub[6-nums2[idx]] += 1;
//             oneAdd[nums2[idx]-1] += 1;
//             sum2 += nums2[idx];
//         }
//         // cout << "sum1 = " << sum1 << "; sum2 = " << sum2 << endl; 
//         int ret = 0;
//         int delta = abs(sum1-sum2);
//         map<int, int> theMap = map<int, int>(sum1 < sum2 ? oneAdd: oneSub);
//         // for( auto i: theMap ){
//         //     cout << i.first << ", " << i.second << endl;
//         // }
//         // cout << "delta = " << delta << endl;
//         for(int i = 5; i >= 1; i--){
//             if(theMap[i]*i >= delta){
//                 ret += delta/i + (delta%i!=0);
//                 break;
//             }else{
//                 // cout << "in <" << endl;
//                 ret += theMap[i];
//                 delta -= theMap[i]*i;
//             }
//         }
//         // copy(nums1.begin(), nums1.end(), ostream_iterator<int>(cout, " "));
//         // cout << endl;
//         // copy(nums2.begin(), nums2.end(), ostream_iterator<int>(cout, " "));
//         // cout << endl;
//         return ret;
//     }
// };


class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > 6*nums2.size() || nums2.size() > 6*nums1.size())
            return -1;
        vector<int> oneAdd = vector<int>(6);
        vector<int> oneSub = vector<int>(6);

        int n1 = nums1.size(), n2 = nums2.size();
        int sum1 = 0, sum2 = 0;
        for(int idx = 0; idx < n1; idx++){
            oneAdd[6-nums1[idx]] += 1;
            oneSub[nums1[idx]-1] += 1;
            sum1 += nums1[idx];
        }
        for(int idx = 0; idx < n2; idx++){
            oneSub[6-nums2[idx]] += 1;
            oneAdd[nums2[idx]-1] += 1;
            sum2 += nums2[idx];
        }
        // cout << "sum1 = " << sum1 << "; sum2 = " << sum2 << endl; 
        int ret = 0;
        int delta = abs(sum1-sum2);
        vector<int> theMap = vector<int>(sum1 < sum2 ? oneAdd: oneSub);
        // for( auto i: theMap ){
        //     cout << i.first << ", " << i.second << endl;
        // }
        // cout << "delta = " << delta << endl;
        for(int i = 5; i >= 1; i--){
            if(theMap[i]*i >= delta){
                ret += delta/i + (delta%i!=0);
                break;
            }else{
                // cout << "in <" << endl;
                ret += theMap[i];
                delta -= theMap[i]*i;
            }
        }
        // copy(nums1.begin(), nums1.end(), ostream_iterator<int>(cout, " "));
        // cout << endl;
        // copy(nums2.begin(), nums2.end(), ostream_iterator<int>(cout, " "));
        // cout << endl;
        return ret;
    }
};