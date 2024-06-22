class Solution {
public:
    bool canPermutePalindrome(string s) {
        std::vector<int> chars('z' - 'a' + 1, 0);
        for(int i = 0 ; i < s.length(); ++i)
            chars[s[i] - 'a']++;

        bool isExistOdd = false;
        for(auto cnt : chars)
        {
            if(cnt%2 != 0)
            {
                if(isExistOdd == true)
                    return false;

                isExistOdd = true;
            }
        }
        
        return true;
    }
};