class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, numeric_limits<int>::max());
        for(int i = 0; i <= n; ++i)
        {
            if(i*i < dp.size())
                dp[i*i] = 1;
            
            if(dp[i] == 1)
                continue;

            for(int j = 1; j*j <= i; ++j)
                dp[i] = min(dp[i], dp[i-j*j] + dp[j*j]);
        }

        return dp[n];
    }
};