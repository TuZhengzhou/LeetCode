/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include<queue>
#include<map>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*
    148 ms	85.3 MB
    使用了 1 个辅助队列
    遍历树 2 次
*/
class Solution {
private:
    queue<TreeNode*> my_queue;
    int vertical_length(TreeNode* root){
        int ret = 0, ret1 = 0, ret2 = 0, val;

        if( root ){
            ret = 0;
            val = root->val;
            if( root->left && root->left->val == val ){
                ret1 = 1 + vertical_length(root->left);
            }else if(root->left){
                my_queue.push(root->left);
            }

            if( root->right && root->right->val == val ){
                ret2 = 1 + vertical_length(root->right);
            }else if(root->right){
                my_queue.push(root->right);
            }
            // printf("ret = %d, ret1 = %d, ret2 = %d, new_ret = %d\n", ret, ret1, ret2, ret1 > ret2 ? ret1 : ret2);
            ret = ret1 > ret2 ? ret1 : ret2;
        }
        return ret;
    }

    int horizontal_length(TreeNode* root){
        int ret = 0, val;
        if( root ){
            val = root->val;
            if( root->left && root->right && root->left->val == val && root->right->val == val ){
                ret = 2 + vertical_length(root->left) + vertical_length(root->right);
            }
            
            if( root->left )    my_queue.push(root->left);
            if( root->right)    my_queue.push(root->right);
        }
        return ret;
    }
public:
    int longestUnivaluePath(TreeNode* root) {
        int max = 0, tmp;
        my_queue.push(root);
        while( !my_queue.empty() ){
            tmp = vertical_length(my_queue.front());
            my_queue.pop();
            max = tmp > max ? tmp : max;
        }

        my_queue.push(root);
        while( !my_queue.empty() ){
            tmp = horizontal_length(my_queue.front());
            my_queue.pop();
            max = tmp > max ? tmp : max;
        }
        return max;
    }
};

/*
    236 ms	97.6 MB
    使用了 2 个辅助队列
    遍历树 2 次
*/
class Solution {
private:
    int max;
    queue<TreeNode*> my_queue;
    map<TreeNode*, int> vertical_length_mapping;
    int vertical_length(TreeNode* root){
        int ret = 0, ret1 = 0, ret2 = 0, val;

        if( root ){
            ret = 0;
            val = root->val;
            if( root->left && root->left->val == val ){
                ret1 = 1 + vertical_length(root->left);
            }else if(root->left){
                my_queue.push(root->left);
            }

            if( root->right && root->right->val == val ){
                ret2 = 1 + vertical_length(root->right);
            }else if(root->right){
                my_queue.push(root->right);
            }
            ret = ret1 > ret2 ? ret1 : ret2;
            vertical_length_mapping[root] = ret;
        }
        return ret;
    }

    int horizontal_length(TreeNode* root){
        int ret = 0, val;
        if( root ){
            val = root->val;
            if( root->left && root->right && root->left->val == val && root->right->val == val ){
                ret = 2 + vertical_length_mapping[root->left] + vertical_length_mapping[root->right];
            }
            
            if( root->left )    my_queue.push(root->left);
            if( root->right)    my_queue.push(root->right);
        }
        return ret;
    }
public:
    int longestUnivaluePath(TreeNode* root) {
        int max = 0, tmp;
        my_queue.push(root);
        while( !my_queue.empty() ){
            tmp = vertical_length(my_queue.front());
            my_queue.pop();
            max = tmp > max ? tmp : max;
        }

        my_queue.push(root);
        while( !my_queue.empty() ){
            tmp = horizontal_length(my_queue.front());
            my_queue.pop();
            max = tmp > max ? tmp : max;
        }
        return max;
    }
};

/*
    128 ms	70.1 MB
    使用了 0 个辅助队列
    遍历树 1 次
*/
class Solution {
private:
    int ans;

    int dfs(TreeNode* root){
        if( root == nullptr ){
            return 0;
        }

        int left = dfs(root->left), right = dfs(root->right);
        int left1 = 0, right1 = 0;
        
        if( root->left && root->left->val == root->val ){
            left1 = left+1;
        }
        if( root->right && root->right->val == root->val ){
            right1 = right+1;
        }
        ans = left1 + right1 > ans ? left1 + right1 : ans;
        
        return std::max(left1, right1);
    }
public:
    int longestUnivaluePath(TreeNode* root) {
        ans = 0;
        dfs(root);
        return ans;
    }
};
