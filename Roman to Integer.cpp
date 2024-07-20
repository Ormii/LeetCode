class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;

        for(int i = 0; i < s.size();)
        {
            ans += convertor(s, i, i);
        }

        return ans;
    }

    int convertor(string& s, int i, int& nextIdx)
    {
        nextIdx = i+1;  
        int val = 0;
        if(s[i] == 'I')
        {
            val = 1;
            if(s.size() > i + 1 && s[i + 1] == 'V')
            {
                val = 4;
                nextIdx = i + 2;
            }
            else if(s.size() > i + 1 && s[i + 1] == 'X')
            {
                val = 9;
                nextIdx = i + 2;
            }
        }
        else if(s[i] == 'X')
        {
            val = 10;
            if(s.size() > i + 1 && s[i + 1] == 'L')
            {
                val = 40;
                nextIdx = i + 2;
            }
            else if(s.size() > i + 1 && s[i + 1] == 'C')
            {
                val = 90;
                nextIdx = i + 2;
            }
        }
        else if(s[i] == 'C')
        {
            val = 100;
            if(s.size() > i + 1 && s[i + 1] == 'D')
            {
                val = 400;
                nextIdx = i + 2;
            }
            else if(s.size() > i + 1 && s[i + 1] == 'M')
            {
                val = 900;
                nextIdx = i + 2;
            }
        }
        else
        {
            switch(s[i])
            {
                case 'V':
                    val = 5; break;
                case 'L':
                    val = 50; break;
                case 'D':
                    val = 500; break;
                case 'M':
                    val = 1000; break;
                default:
                    break;
            }
        }
        return val;
    }
};