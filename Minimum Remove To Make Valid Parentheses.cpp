class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> RemoveIndexs;
        string Ans = "";
        for(auto& Char : s)
        {
            if(Char != '(' && Char != ')')
            {
                Ans += Char;
                continue;
            }

            if(Char == '(')
            {
                Ans += Char;
                RemoveIndexs.push(Ans.length()-1);
            }
            else if(Char == ')')
            {
                if(!RemoveIndexs.empty())
                {
                    RemoveIndexs.pop();
                    Ans += Char;
                }
            }
        }

        while(!RemoveIndexs.empty())
        {
            int Index = RemoveIndexs.top();
            RemoveIndexs.pop();
            Ans.erase(Ans.begin() + Index);
        }

        return Ans;
    }
};