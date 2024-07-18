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
    int ans = 0;
    queue<TreeNode*> que;
    unordered_map<TreeNode*,pair<TreeNode*,bool>> um;
public:
    int countPairs(TreeNode* root, int distance) {
    
        postorder(root, nullptr);

        while(!que.empty())
        {
            TreeNode* leafnode = que.front();
            que.pop();

            for(auto&obj : um)
                obj.second.second = false;

            dfs(leafnode, leafnode, distance);
        }

        ans /= 2;
        return ans;
    }

    void postorder(TreeNode* node, TreeNode* parent)
    {
        if(node == nullptr)
            return;

        postorder(node->left, node);
        postorder(node->right, node);

        if(node->left == nullptr && node->right == nullptr)
            que.push(node);

        um.insert({node, make_pair(parent,false)});
    }

    void dfs(TreeNode* node,TreeNode* startNode, int step)
    {
        if(node == nullptr)
            return;

        if(um[node].second == true)
            return;

        if(step < 0)
            return;

        um[node].second = true;

        if(node->left == nullptr && node->right == nullptr && node != startNode)
        {
            ans++;
            return;
        }

        dfs(node->left, startNode, step - 1);
        dfs(node->right, startNode, step - 1);
        
        TreeNode* parent = um[node].first;
        if(parent != nullptr)
            dfs(parent, startNode, step - 1);
    }
};