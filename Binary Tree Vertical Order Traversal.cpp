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
private:
    int minValue;
    int maxValue;
    
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        queue<pair<TreeNode*,int>> que;
        map<int,vector<int>> m;

        que.push(make_pair(root, 0));
        while(!que.empty())
        {
            auto obj = que.front();
            que.pop();

            TreeNode* node = obj.first;
            int val = obj.second;

            if(node == nullptr)
                continue;
            
            if(m.find(val) == m.end())
                m.insert(make_pair(val, vector<int>()));

            m[val].push_back(node->val);

            que.push(make_pair(node->left,val-1));
            que.push(make_pair(node->right,val+1));

            if(minValue > val)
                minValue = val;
            if(maxValue < val)
                maxValue = val;
        }
        
        if(m.size() == 0)
            return vector<vector<int>>();

        vector<vector<int>> ans(maxValue - minValue + 1);
        for(auto& obj : m)
        {
            for(auto i : obj.second)
                ans[obj.first-minValue].push_back(i);
        }

        return ans;
    }
};