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
    ListNode* swapPairs(ListNode* head) {
        ListNode* tmp = head;
        ListNode* preNode = nullptr;
        while(tmp != nullptr && tmp->next != nullptr)
        {
            ListNode* NextNode = tmp->next;
            
            tmp->next = NextNode->next;
            NextNode->next = tmp;
            if(preNode == nullptr)
                head = NextNode;
            else
                preNode->next = NextNode;
            preNode = tmp;
            tmp = tmp->next;
        }

        return head;
    }
};