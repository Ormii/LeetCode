class Solution {

private:
    vector<string> ans;

public:
    void recursive(string s, int openCnt, int closeCnt)
    {
        if(openCnt == 0 && closeCnt == 0)
        {
            ans.push_back(s);
            return;
        }

        if(openCnt == closeCnt)
        {
            string op = s;
            op.push_back('(');
            recursive(op,openCnt-1,closeCnt);
        }
        else if(openCnt == 0)
        {
            string op = s;
            op.push_back(')');
            recursive(op,openCnt,closeCnt-1);
        }
        else
        {
            string op1 = s;
            string op2 = s;
        
            op1.push_back('(');
            recursive(op1,openCnt-1,closeCnt);
            
            op2.push_back(')');
            recursive(op2,openCnt,closeCnt-1);
        }
    }

    vector<string> generateParenthesis(int n) {
        string s = "";
        recursive(s,n,n);

        return ans;
    }
};