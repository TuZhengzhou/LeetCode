// #include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {

        std::sort(arr.begin(), arr.end());
        std::sort(target.begin(), target.end());

        bool ret = true;
        for( auto s_iter = arr.begin(), t_iter = target.begin(); s_iter != arr.end(); s_iter++, t_iter++ ){
            if( *s_iter != *t_iter ){
                ret = false;
                break;
            }
        }
        return ret;
    }
};