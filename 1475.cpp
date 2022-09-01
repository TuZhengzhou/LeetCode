#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    // 简单遍历, 4 ms	9.6 MB
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> ret(prices.size(), 0);

        int i, j, n = prices.size();
        for( i = 0; i < n; i++ ){
            for( j = i+1; j < n; j++ ){
                if( prices[j] <= prices[i] )    break;
            }
            if( j == n )
                ret[i] = prices[i];
            else
                ret[i] = prices[i]-prices[j];
        }

        return ret;
    }

    // 单调栈, 0 ms	9.8 MB
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> ret(prices.size(), 0);
        stack<int> my_stack;

        int i, n = prices.size();
        for( i = n-1; i >= 0; i-- ){
            int tmp = prices[i];
            while( !my_stack.empty() && my_stack.top() > tmp ){
                my_stack.pop();
            }
            if(my_stack.empty())
                ret[i] = tmp;
            else
                ret[i] = tmp-my_stack.top();
            my_stack.push(tmp);
        }

        return ret;
    }
};