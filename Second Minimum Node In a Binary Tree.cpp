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
    void inorder(TreeNode* node,int min_val ,int& second_min)
    {
        if(node == nullptr)
            return;

        if(node->val >min_val)
        {
            if(second_min == -1)
                second_min = node->val;
            else
                second_min = min(second_min,node->val);

            return;    
        }

        inorder(node->left, min_val, second_min);
        inorder(node->right, min_val, second_min);
    }

    int findSecondMinimumValue(TreeNode* root) {
        int ans = -1;
        inorder(root, root->val, ans);

        return ans;        
    }
};