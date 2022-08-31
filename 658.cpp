#include<iostream>
#include<cmath>
#include<vector>

using namespace std;
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int low, mid, high, start, counter;
        vector<int> ret;
 
        // 找到第一个大于等于 x 的元素的位置
        mid = 0;
        for( ; mid < arr.size(); mid++ ){
            if(arr[mid] >= x)  break;
        }
        
        counter = 0;
        low = mid-1;
        high = mid;
        while(counter < k){
            if( low < 0 || high >= arr.size() ){
                break;
            }
            if( (x-arr[low]) <= (arr[high]-x) ){
                start = low;
                low--;
                counter++;
            }else{
                start = high-k+1;
                high++;
                counter++;
            }
        }
        start = low < 0 ? 0 : (high >= arr.size() ? arr.size()-k : start);
        
        for(auto i = start; i < start+k; i++){
            ret.push_back(arr[i]);
        }
        return ret;
    }
};

class Solution1 {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> ans;
        int n = arr.size();
        int l = 0, r = n - 1;
        for(int i = 0; i < n - k; i ++)
            if(std::abs(x - arr[l]) <= std::abs(arr[r] - x)) r --;
            else l ++;
        
        for(int i = l; i <= r; i ++)
            ans.push_back(arr[i]);
        return ans;
    }
};