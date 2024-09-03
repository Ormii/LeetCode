class Solution {
private:
    string convert2numstr(string s)
    {
        string convertstr = "";
        for(int i = 0; i < s.length(); i++)
            convertstr += to_string((int)(s[i]-'a'+1));

        return convertstr;
    }

    int sumDigit(string s)
    {
        int result = 0;
        for(int i = 0; i < s.length(); ++i)
            result += s[i] - '0';

        return result;
    }

public:
    int getLucky(string s, int k) {
        string convertstr = convert2numstr(s);

        int result = 0;
        for(int i = 0; i < k; ++i)
        {
            result = sumDigit(convertstr);
            convertstr = to_string(result);
        }
            
        return result;
    }
};