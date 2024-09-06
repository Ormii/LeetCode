/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        
        sort(nums.begin(), nums.end());

        ListNode dummy;
        dummy.next = head;

        ListNode* node = &dummy;
        while(node != nullptr)
        {
            if(node->next != nullptr && 
            binarySearch(nums,0, nums.size()-1, node->next->val))
            {
                node->next = node->next->next;
            }
            else
                node = node->next;
        }

        return dummy.next;
    }

    bool binarySearch(vector<int>& nums, int left, int right, int value)
    {
        while(left <= right)
        {
            int mid = (left + right)/2;
            if(value == nums[mid])
                return true;
            else if(value > nums[mid])
                left = mid + 1;
            else
                right = mid - 1;
        }

        return false;
    }
};