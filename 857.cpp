#include <numeric>      // std::iota
#include<vector>
#include<queue>         // std::priority_queue
using namespace std;
class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();
        vector<int> h = vector<int>(n, 0);
        iota(h.begin(), h.end(), 0);
        sort(h.begin(), h.end(), [&](int& a, int& b){
            return (double)wage[a]/quality[a] < (double)wage[b]/quality[b];
        });
        double res = 1E9;
        int sum_q = 0;
        priority_queue<int> big_top;
        for( int i = 0; i < k-1; i++ ){
            sum_q += quality[h[i]];
            big_top.push(quality[h[i]]);
        }
        for( int i = k-1; i < n; i++ ){
            int idx = h[i];
            sum_q += quality[idx];
            big_top.push(quality[idx]);
            res = min(res, (double)wage[idx]/quality[idx]*sum_q);
            sum_q -= big_top.top();
            big_top.pop();
        }
        return res;
    }
};