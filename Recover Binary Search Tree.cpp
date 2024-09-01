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
    void inorder(TreeNode* root, vector<int>& nums)
    {
        if(root == nullptr) return;
        inorder(root->left, nums);
        nums.push_back(root->val);
        inorder(root->right, nums);
    }

    vector<int> findTwoSwapped(vector<int> nums)
    {
        int n = nums.size();
        int x = -1, y = -1;
        bool swapped_first_occurence = false;
        for(int i = 0; i < n - 1; i++)
        {
            if(nums[i+1] < nums[i])
            {
                y = nums[i+1];
                if(!swapped_first_occurence)
                {
                    x = nums[i];
                    swapped_first_occurence = true;
                }
                else
                {
                    break;
                }
            }
        }

        return vector<int>{x,y};
    }

    void recover(TreeNode* r, int count, int x, int y)
    {
        if(r != nullptr)
        {
            if(r->val == x || r->val == y)
            {
                r->val = r->val == x ? y : x;
                if(--count == 0)return;
            }
            recover(r->left, count, x, y);
            recover(r->right, count, x, y);
        }
    }

    void recoverTree(TreeNode* root)
    {
        vector<int> nums;
        inorder(root, nums);
        vector<int> swapped = findTwoSwapped(nums);
        recover(root, 2, swapped[0], swapped[1]);
    }
};