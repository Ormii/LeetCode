class Solution {
public:
    int calculate(string s) {
        std::stack<int> st;
        std::stack<char> op;
        string postfix;

        ToPostfix(s, postfix);

        for(int i = 0; i < postfix.length(); i++)
        {
            char c = postfix[i];

            if(isdigit(c))
            {
                int val = 0;
                while(isdigit(postfix[i]) && i < postfix.length())
                    val = 10*val + (postfix[i++]-'0');
                st.push(val);
            }
            else if(c == '+' || c == '-' || c == '*' || c == '/')
            {
                int r = st.top(); st.pop();
                int l = st.top(); st.pop();

                switch(c)
                {
                    case '+': st.push(l + r);break;
                    case '-': st.push(l - r);break;
                    case '*': st.push(l * r);break;
                    case '/': st.push(l / r);break;
                    default: break;
                }
            }
        }

        return st.top();
    }

    void ToPostfix(const string& s, string& postfix)
    {
        std::stack<char> op;
        
        for(auto& c : s)
        {
            if(c == ' ')
                continue;

            if(isdigit(c))
            {
                postfix.push_back(c);
            }
            else if(c == '+' || c == '-' || c == '*' || c == '/')
            {
                postfix.push_back(' ');
                while(!op.empty() && priority(op.top()) >= priority(c))
                {
                    postfix.push_back(op.top());
                    postfix.push_back(' ');
                    op.pop();
                }

                op.push(c);
            }
        }

        while(!op.empty())
        {
            postfix.push_back(' ');
            postfix.push_back(op.top());
            op.pop();
        }
    }

    int priority(char c)
    {
        if(c == '+' || c == '-')return 0;
        else if(c == '*' || c == '/') return 1;

        return 2;
    }
};