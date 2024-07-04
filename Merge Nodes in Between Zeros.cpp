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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* node = head;
        ListNode ans;
        ListNode *anshead = &ans;

        while(node != nullptr)
        {
            if(node->val == 0)
            {
                node = node->next;
                continue;
            }

            anshead->next = FindSumNode(node, &node);
            anshead = anshead->next;
        }      

        return ans.next;
    }

    ListNode* FindSumNode(ListNode* head, ListNode** nextHead)
    {
        ListNode* SumNode = nullptr;
        while(head != nullptr && head->val != 0)
        {
            if(SumNode == nullptr)
                SumNode = new ListNode();
            
            SumNode->val += head->val;
            head = head->next;
        }

        if(nextHead != nullptr)
            *nextHead = head;

        return SumNode;
    }
};