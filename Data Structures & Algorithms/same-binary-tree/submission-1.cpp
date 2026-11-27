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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return sameTreeDfs(p, q);
    }
    bool sameTreeDfs(TreeNode* p, TreeNode* q) {
        if(p == nullptr && q == nullptr) {
            return true;
        }
        if(p == nullptr ^ q == nullptr) {
            return false;
        }
        if(p->val != q->val) {
            return false;
        }
        
        // if (p->left == nullptr && p->right == nullptr && q->left == nullptr && q->right == nullptr)     {
        //     return true;
        // }
        

        return sameTreeDfs(p->left, q->left) && sameTreeDfs(p->right, q->right);
    }
};
