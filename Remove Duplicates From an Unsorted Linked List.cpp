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
    ListNode* deleteDuplicatesUnsorted(ListNode* head) {
        unordered_map<int,int> um;
        ListNode tmp(0, head);

        for(auto p = head ; p != nullptr; p = p->next)
            ++um[p->val];
        
        for(auto p = &tmp, c = &tmp; p != nullptr; p = p->next)
        {
            c->next = p->next;
            if(p->next && um[p->next->val] == 1)
                c = c->next;
        }

        return tmp.next;
    }
};