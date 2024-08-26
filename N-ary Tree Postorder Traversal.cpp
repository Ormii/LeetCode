/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
private:
    vector<int> answer;

public:
    vector<int> postorder(Node* root) {
        recv(root);
        return answer;
    }

    void recv(Node* root)
    {
        if(root == nullptr)
            return;

        for(auto& child : root->children)
            recv(child);
        
        answer.push_back(root->val);
    }
};