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
    bool balanced = true;
    bool isBalanced(TreeNode* root) {
        depth(root);
        return balanced;
    }

    int depth(TreeNode* root) {
        if(root == nullptr) {
            return 0;
        }
        int depthRight = depth(root->right);
        int depthLeft = depth(root->left);
        if (abs(depthRight - depthLeft) > 1) {
            balanced = false;
        }
        return 1 + max(depthRight, depthLeft);
    }
};
