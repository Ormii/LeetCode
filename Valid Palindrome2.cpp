class Solution {
public:
    bool recursive(string s, int left, int right, bool isDeleted)
    {
        while(left < right && s[left] == s[right])
        {
            ++left;
            --right;
        }

        if(left >= right)
            return true;

        if(isDeleted == true)
            return false;
        
        bool result = false;
        result = recursive(s, left+1, right, true) || recursive(s,left, right-1, true);
        
        return result;
    }

    bool validPalindrome(string s) {
        return recursive(s, 0, s.length()-1, false);
    }
};