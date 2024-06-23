class Solution {
public:
    int countSubstrings(string s) {
        vector<vector<bool>> dp(s.length(), vector<bool>(s.length(), false));
        for(int i = 0 ; i < s.length(); ++i)
        {
            dp[i][i] = true;
            for(int j = 0; j < i; ++j)
            {
                if(s[j] == s[i] && (i - j <= 2 || dp[j+1][i-1] == true))
                    dp[j][i] = true;
            }
        }

        int ans = 0;
        for(int i = 0; i < s.length(); ++i)
            for(int j = i; j < s.length(); ++j)
                if(dp[i][j] == true)
                    ans++;

        return ans;
    }
};