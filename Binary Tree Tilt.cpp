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
    int postorder(TreeNode* root, int& ans)
    {
        if(root == nullptr)
            return 0;

        int lvalue = postorder(root->left, ans);
        int rvalue = postorder(root->right, ans);
        int mvalue = root->val;

        ans += abs(lvalue - rvalue);

        return lvalue + rvalue + mvalue;
    }

    int findTilt(TreeNode* root) {
        int ans = 0;
        int tot = 0;

        tot = postorder(root, ans);
        return ans;
    }
};