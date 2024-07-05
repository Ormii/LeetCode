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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> CriticalNodes;
        vector<int> Ans(2);
        ListNode* Node = head;
        int Dist = 1;
        while(Node->next->next != nullptr)
        {
            ListNode* NextNode = Node->next;
            ListNode* NNextNode = NextNode->next;
            
            if(Node->val > NextNode->val && NextNode->val < NNextNode->val)
                CriticalNodes.push_back(Dist);
            else if(Node->val < NextNode->val && NextNode->val > NNextNode->val)
                CriticalNodes.push_back(Dist);
            
            Dist++;
            Node = NextNode;
        }

        if(CriticalNodes.size() < 2)
            Ans[0] = Ans[1] = -1;
        else
        {
            int minDistance = numeric_limits<int>::max();
            int maxDistance = CriticalNodes[CriticalNodes.size()-1] - CriticalNodes[0];
            for(int i = 0 ; i < CriticalNodes.size()-1; ++i)
                minDistance = min(minDistance, CriticalNodes[i+1] - CriticalNodes[i]); 
        
            Ans[0] = minDistance;
            Ans[1] = maxDistance;
        }

        return Ans;
    }
};