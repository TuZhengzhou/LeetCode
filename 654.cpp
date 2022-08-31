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
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if( nums.size() == 0 ){
            return nullptr;
        }
        int max_pos = max_element(nums.begin(), nums.end())-nums.begin();
        TreeNode* ret = new TreeNode(nums[max_pos]);

        vector<int>::iterator head, tail;
        head = tail = nums.begin();
        advance(tail, max_pos);
        vector<int> left_nums(head, tail);
        printf("left_size=%d\n", left_nums.size());
        ret->left = constructMaximumBinaryTree( left_nums );

        head = tail;
        tail = nums.end();
        vector<int> right_nums(head, tail);
        printf("right_size=%d\n", right_nums.size());
        ret->right = constructMaximumBinaryTree(right_nums);

        return ret;
    }
};