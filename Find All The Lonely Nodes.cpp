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
    void postorder(TreeNode* node, vector<int>& ans)
    {
        if(node == nullptr)
            return;
        
        postorder(node->left,ans);
        postorder(node->right,ans);

        if(node->left == nullptr && node->right != nullptr)
            ans.push_back(node->right->val);
        else if(node->left != nullptr && node->right == nullptr)
            ans.push_back(node->left->val);
    }

    vector<int> getLonelyNodes(TreeNode* root) {
        vector<int> ans;
        postorder(root, ans);

        return ans;
    }
};