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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        TreeNode* RootNode = nullptr;

        unordered_map<int,pair<TreeNode*,int>> um;
        for(auto& description : descriptions)
        {
            int parent = description[0];
            int child = description[1];
            bool isLeft = description[2];

            if(um.find(parent) == um.end())
                um.insert({parent, make_pair(new TreeNode(parent), 0)});
            if(um.find(child) == um.end())
                um.insert({child, make_pair(new TreeNode(child), parent)});

            if(isLeft)
                um[parent].first->left = um[child].first;
            else
                um[parent].first->right = um[child].first;
            
            um[child].second = parent;
        }

        for(auto& nodeinfo : um)
        {
            if(nodeinfo.second.second==0)
            {
                RootNode = nodeinfo.second.first;
                break;
            }
        }

        return RootNode;   
    }
};