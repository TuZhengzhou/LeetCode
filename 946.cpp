#include<list>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        list<int> my_stack;
        int n = pushed.size();
        int idx_poped = 0;
        for( int i = 0; i < n; i++ ){
            if(pushed[i] == popped[idx_poped]){
                idx_poped++;
                while(idx_poped < n && !my_stack.empty() && my_stack.back() == popped[idx_poped]){
                    idx_poped++;
                    my_stack.pop_back();
                }
            }else{
                my_stack.push_back(pushed[i]);
            }
        }
        return idx_poped == n;
    }
};

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> my_stack;
        int n = pushed.size();
        int idx_poped = 0;
        for( int i = 0; i < n; i++ ){
            if(pushed[i] == popped[idx_poped]){
                idx_poped++;
                while(idx_poped < n && !my_stack.empty() && my_stack.top() == popped[idx_poped]){
                    idx_poped++;
                    my_stack.pop();
                }
            }else{
                my_stack.push(pushed[i]);
            }
        }
        return idx_poped == n;
    }
};