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

class Solution {
public:

    /*
        由于 val 在序列最后, 所以 val 所在节点要么是根节点, 要么总是某个节点的右节点
        为了统一情况, 我们可以在 序列头 加上一个 max_val+1
            原树成为 max_val+1 节点的右子树
            且当 val 仅小于 max_val+1 时, val 节点会成为 max_val+1 节点的右节点

        即, 在序列头添加 max_val+1 后, 总是有:
            val 所在节点总是某个节点的右节点, 且

            a, b, c, ... , val 所形成的的最大二叉树 T1 是
            max+1, a, b, c, ... , val 所形成的最大二叉树 T2 的右子树
    */
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        TreeNode* my_root = new TreeNode(101, nullptr, root);
        my_insert(my_root, val);
        return my_root->right;
    }
    int my_insert(TreeNode* root, int val){
        if( root ){
            if( root->val > val ){
                if( my_insert(root->right, val) ){      // 能否插入，如果能够，说明 val 比右子树的根节点的 val 值小
                    return 1;
                }
                // 不能插入，说明 val 比右子树的根节点的 val值大
                // 又因为 val 在序列里排最后, 所以 root 的右子树会成为 新节点的 左子树, 新结点成为 root 的右子树
                TreeNode* add = new TreeNode(val, root->right, nullptr);
                root->right = add;
                return 1;
            }
        }
        return 0;
    }
};