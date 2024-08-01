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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> answer;
        dfs(root, 0, answer);

        return answer;
    }

    void dfs(TreeNode* root, int depth, vector<vector<int>>& v)
    {
        if(root == nullptr)
            return;

        if(v.size() <= depth)
            v.push_back(vector<int>());
        
        v[depth].push_back(root->val);
        dfs(root->left, depth + 1, v);
        dfs(root->right, depth + 1, v);
    }
};