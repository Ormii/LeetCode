class Solution {
public:
    string reverseOnlyLetters(string s) {
        int i = 0;
        vector<char> chars;
        for(auto c : s)
            if(isalpha(c))
                chars.push_back(c);

        auto riter = chars.rbegin();
        for(; riter != chars.rend() && i < s.size(); i++)
        {
            if(isalpha(s[i]))
                s[i] = *riter++;
        }

        return s;
    }
};