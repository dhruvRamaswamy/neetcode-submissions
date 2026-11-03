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
    int maxDiameter = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return maxDiameter;
    }
    int dfs(TreeNode* root) {
        if(root == nullptr) {
            return 0;
        }
        else {
            int leftMax = dfs(root->left);
            int rightMax = dfs(root->right);
            maxDiameter = max(leftMax + rightMax, maxDiameter);
            printf("Root val: %d, left + right: %d\n", root->val, leftMax + rightMax);
            return 1 + max(rightMax, leftMax);
        }
        
    }
};
