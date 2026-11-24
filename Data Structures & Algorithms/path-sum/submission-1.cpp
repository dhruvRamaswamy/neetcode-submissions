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
    bool hasPathSum(TreeNode* root, int targetSum)  {
        if (!root) return false;
        // Key data structure, notice
        queue<pair<TreeNode*, int>> q;
        q.push({root, root ->val});
        while(!q.empty()) {
            auto [node, currSum] = q.front();
            q.pop();

            // If you have reached a leaf node
            if(!node->left && !node->right && currSum == targetSum) {
                return true;
            }
            // Otherwise add to queue
            if(node->left) {
                q.push({node->left, currSum + node->left->val});
            }
            if(node->right) {
                q.push({node->right, currSum + node->right->val});
            }
            
        }
        return false;
    }
    
};