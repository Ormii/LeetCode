class Solution {
public:
    string longestPalindrome(string s) {
        if(s.length() <= 1)
            return s;

        int max_len = 1;
        int rightIdx = 0, centerIdx = 0;
        
        string ans = s.substr(0,1);
        s = "#" + std::regex_replace(s, std::regex(""), "#") + "#";
        std::vector<int> radius(s.length(),0);

        for(int i = 0; i < s.length(); ++i)
        {
            if(i < rightIdx)
                radius[i] = min(radius[2*centerIdx - i], radius[rightIdx - 1]);

            while(i - radius[i] - 1 >= 0 && i + radius[i] + 1 < s.length() - 1 &&
            s[i - radius[i] - 1] == s[i + radius[i] + 1])
                radius[i]++;
            
            if(max_len < radius[i])
            {
                max_len = radius[i];
                centerIdx = i;
                rightIdx = i + radius[i];
            
                ans = s.substr(centerIdx - radius[i], 2* radius[i] + 1);
                ans.erase(std::remove(ans.begin(), ans.end(), '#'), ans.end());
            }
        }
        
    return ans;
    }
};