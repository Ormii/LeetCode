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
    int result;

public:
    int findDistance(TreeNode* root, int p, int q) {
        if(p == q)
            return 0;

        result = -1;
        Dfs(root, p, q);
        return result;
    }

    int Dfs(TreeNode* root, int p, int q)
    {
        if(root == nullptr)
            return -1;
        
        int left = Dfs(root->left, p, q);
        int right = Dfs(root->right, p, q);
        
        if(root->val == p || root->val == q)
        {
            if(left < 0 && right < 0)
                return 0;
            
            result = 1 + (left > right ? left : right);
            return -1;
        }
            

        if(left >= 0 && right >= 0)
        {
            result = left + right + 2;
            return -1;
        }
        
        if(left >= 0)
        {
            return left + 1;
        }

        if(right >= 0)
        {
            return right + 1;
        }

        return -1;
    }
};