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
    bool Result;
    string ResultStr = "";
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        Result = false;
        string ans = "";

        TreeNode* ancestor = LCA(root, startValue, destValue);

        string s = "";
        string StartStr = "";
        string DestStr = "";
        FindNode(ancestor,false,startValue,s);
        StartStr = ResultStr;

        FindNode(ancestor,true,destValue,s);
        DestStr = ResultStr;

        reverse(StartStr.begin(), StartStr.end());

        ans = StartStr + DestStr;

        return ans;
    }

    TreeNode* LCA(TreeNode* root, int p, int q)
    {
        if(root == nullptr)
            return nullptr;

        if(root->val == p || root->val == q)
        {
            return root;
        }

        TreeNode* Left = LCA(root->left, p, q);
        TreeNode* Right = LCA(root->right, p, q);

        if(Left != nullptr && Right != nullptr)
        {
            return root;
        }

        if(Left != nullptr)
            return Left;
        else if(Right != nullptr)
            return Right;

        return nullptr;
    }

    void FindNode(TreeNode* root, bool bDest, int value, string& s)
    {
        if(Result)
            return;

        if(root == nullptr)
            return;

        if(root->val == value)
        {
            ResultStr = s;
            return;
        }

        if(bDest)
        {
            s.push_back('L');
            FindNode(root->left, bDest, value, s);
            s.pop_back();

            s.push_back('R');
            FindNode(root->right, bDest, value, s);
            s.pop_back();
        }   
        else
        {
            s.push_back('U');
            FindNode(root->left, bDest, value, s);
            s.pop_back();

            s.push_back('U');
            FindNode(root->right, bDest, value, s);
            s.pop_back();
        }   
    }
};