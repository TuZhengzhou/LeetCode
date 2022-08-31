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
#include<iostream>
#include<algorithm>
#include<list>
#include<utility>
using namespace std;

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        int current, next;
        int low, high, now;
        int max = -1;
        list<TreeNode*> lists[2];
        lists[0].clear();
        lists[1].clear();
        
        current = 0;
        lists[current].push_back(root);

        
        while( !lists[current].empty() ){
            low = -1; high = -1; now = 0;
            next = (current + 1) % 2;

            lists[next].clear();
            for( auto item: lists[current] )
            {
                if( item != nullptr )
                {
                    if( low == -1 ) low = now;          // 找到最左边的非 null 元素
                    if( now > high ) high = now;        // 找到最右边的非 Null 元素
                    lists[next].push_back(item->left);  // 左孩子, 放入下一层的记录里
                    lists[next].push_back(item->right); // 右孩子, 放入下一层的记录里
                }
                else
                {
                    lists[next].push_back(nullptr);
                    lists[next].push_back(nullptr);
                }
                
                now++;
            }
            printf("low = %d, high = %d\n", low, high);
            if( low == -1 && high == -1 )   break;

            current = next;
            max = max > (high-low+1) ? max : high-low+1;
        }
        return max;
    }
};

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



struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// class Solution {
// public:
//     int widthOfBinaryTree(TreeNode* root) {
//         int current, next;
//         int low, high, now;
//         int max = -1;
//         list<TreeNode*> lists[2];
//         list<TreeNode*> tmp_list;
//         lists[0].clear();
//         lists[1].clear();
        
//         current = 0;
//         lists[current].push_back(root);

        
//         while( !lists[current].empty() ){
//             low = -1; high = -1; now = 0;
//             next = (current + 1) % 2;

//             lists[next].clear();
//             tmp_list.clear();
//             for( auto item: lists[current] )
//             {
//                 if( item != nullptr )
//                 {
//                     if( low == -1 ){
//                         low = now;          // 找到最左边的非 null 元素
//                     }
//                     if( now > high ){
//                         high = now;        // 找到最右边的非 Null 元素
//                         for( auto )
//                     }
//                     if( low != -1 ){        // 左边已经找到了
//                         tmp_list.push_back(item->left);
//                         tmp_list.push_back(item->right);
//                     }
//                 }
//                 else
//                 {
                    
//                     lists[next].push_back(nullptr);
//                     lists[next].push_back(nullptr);
//                 }
//                 now++;
//             }
//             if( low == -1 && high == -1 )   break;

//             current = next;
//             max = max > (high-low+1) ? max : high-low+1;
//         }
//         return max;
//     }
// };


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

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        int current, next;
        int start_point, low, high, now;
        int max = -1;
        pair<TreeNode*, int> item;
        list<pair<TreeNode*, int>> lists[2];

        lists[0].clear();
        lists[1].clear();
        
        current = 0;
        lists[current].push_back(make_pair(root, 0));

        while( !lists[current].empty() ){
            low = -1; high = -1; now = 0;
            next = (current + 1) % 2;

            lists[next].clear();
            for( auto item: lists[current] )
            {
                if( item.first != nullptr )
                {
                    now = item.second;
                    if( low == -1 ){
                        start_point = now;
                        low = 0;
                        high = 0;
                    }
                    high = now - start_point;       // 相对 start_point 的右偏移
                    
                    if( item.first->left != nullptr )
                        lists[next].push_back(make_pair(item.first->left, high*2));  // 左孩子, 放入下一层的记录里
                    if( item.first->right != nullptr )
                        lists[next].push_back(make_pair(item.first->right, high*2+1)); // 右孩子, 放入下一层的记录里
                }
            }
            current = next;
            max = max > (high-low+1) ? max : high-low+1;

            printf("low = %d, high = %d\n", low, high);
            printf("len = %d\n", lists[next].size());
        }
        return max;
    }
};

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        int current, next;
        int low, high, now;
        int max = -1;
        list<TreeNode*> lists[2];
        list<TreeNode*>::iterator iter;

        lists[0].clear();
        lists[1].clear();
        
        current = 0;
        lists[current].push_back(root);

        
        while( !lists[current].empty() ){
            low = -1; high = -1; now = 0;
            next = (current + 1) % 2;

            lists[next].clear();
            for( auto item: lists[current] )
            {
                if( item != nullptr )
                {
                    if( low == -1 ) low = now;          // 找到最左边的非 null 元素
                    if( now > high ) high = now;        // 找到最右边的非 Null 元素
                    lists[next].push_back(item->left);  // 左孩子, 放入下一层的记录里
                    lists[next].push_back(item->right); // 右孩子, 放入下一层的记录里
                }
                else
                {
                    lists[next].push_back(nullptr);
                    lists[next].push_back(nullptr);
                }
                now++;
            }
            printf("low = %d, high = %d\n", low, high);
            if( low == -1 && high == -1 )   break;

            iter = lists[next].begin();
            advance(iter, 2*(high+1));
            lists[next].erase(iter, lists[next].end());

            iter = lists[next].begin();
            advance(iter, 2*low);
            lists[next].erase(lists[next].begin(), iter);

            printf("len = %d\n", lists[next].size());
            current = next;
            max = max > (high-low+1) ? max : high-low+1;
        }
        return max;
    }
};


// 4 ms	17.2 MB	
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
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        int current, next, low;
        unsigned int start_point, high, now, max=0;
        list<pair<TreeNode*, unsigned int>> lists[2];

        current = 0;
        lists[current].clear();
        lists[current].push_back(make_pair(root, 0));

        while( !lists[current].empty() ){
            low = -1; high = 0; now = 0;
            next = (current + 1) % 2;

            lists[next].clear();
            for( auto item: lists[current] )
            {
                now = item.second;
                if( low == -1 ){
                    start_point = now;
                    low = 0;
                    high = 0;
                }
                high = now - start_point;       // 相对 start_point 的右偏移
                
                if( item.first->left != nullptr )
                    lists[next].push_back(make_pair(item.first->left, high*2));  // 左孩子, 放入下一层的记录里
                if( item.first->right != nullptr )
                    lists[next].push_back(make_pair(item.first->right, high*2+1)); // 右孩子, 放入下一层的记录里
            }
            current = next;
            max = max > (high+1) ? max : high+1;
        }
        return max;
    }
};