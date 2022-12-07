#include<vector>
#include<algorithm>
#include<numeric>

using namespace std;

class Solution {
public:
    const int MAX = 10000000;
    inline int manhattanDist(int x1, int x2, int y1, int y2){
        if(x1 == x2 || y1 == y2)
            return abs(x1-x2)+abs(y1-y2);
        else
            return MAX;
    }
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {

        // 与官方不太一样的思路
        // vector<int> vec = vector<int>(points.size());
        // std::iota (vec.begin(),vec.end(),0);

        // vector<int> dists;
        // for(vector<int> point: points){
        //     dists.push_back(manhattanDist(x, point[0], y, point[1]));
        // }

        // sort(vec.begin(), vec.end(), [&dists](int a, int b){
        //     return dists[a] < dists[b] || (dists[a] == dists[b] && a < b);
        // });
        
        // return dists[vec[0]] < MAX ? vec[0] : -1;


        // 跟官方差不多的思路
        int min_idx = -1;
        int min_val = numeric_limits<int>::max();
        int n = points.size();
        int dist;
        for(int idx = 0; idx < n; idx++){
            int a = points[idx][0];
            int b = points[idx][1];
            if(x == a || y == b){
                dist = abs(x-a)+abs(y-b);
                if(dist < min_val){
                    min_val = dist;
                    min_idx = idx;
                }
            }
        }
        return min_idx;

        // 官方的答案
        // int n = points.size();
        // int best = numeric_limits<int>::max(), bestid = -1;
        // for (int i = 0; i < n; ++i) {
        //     int px = points[i][0], py = points[i][1];
        //     if (x == px) {
        //         if (int dist = abs(y - py); dist < best) {
        //             best = dist;
        //             bestid = i;
        //         }
        //     }
        //     else if (y == py) {
        //         if (int dist = abs(x - px); dist < best) {
        //             best = dist;
        //             bestid = i;
        //         }
        //     }
        // }
        // return bestid;
        
    }
};

