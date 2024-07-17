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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_map<int,pair<TreeNode*, int>> um;
        
        postOrder(root, nullptr, um);
        for(auto& del : to_delete)
        {
            TreeNode* node = um[del].first;
            int parentVal = um[del].second;

            if(node->left != nullptr && um.find(node->left->val) != um.end())
                um[node->left->val].second = 0;

            if(node->right != nullptr && um.find(node->right->val) != um.end())
                um[node->right->val].second = 0;
        
            if(parentVal != 0)
            {
                TreeNode* parent = um[parentVal].first;
                if(parent->left != nullptr && parent->left->val == node->val)
                    parent->left = nullptr;
            
                if(parent->right != nullptr && parent->right->val == node->val)
                    parent->right = nullptr;
            }

            um.erase(del);
        }

        vector<TreeNode*> ans;
        for(auto& obj : um)
        {
            if(obj.second.second == 0)
                ans.push_back(obj.second.first);
        }

        return ans;
    }

    void postOrder(TreeNode* root, TreeNode* parent ,unordered_map<int,pair<TreeNode*, int>>& um)
    {
        if(root == nullptr)
            return;

        postOrder(root->left, root, um);
        postOrder(root->right, root, um);

        int parentVal = 0;
        if(parent != nullptr)
            parentVal = parent->val;

        um.insert({root->val, make_pair(root, parentVal)});
    }
};