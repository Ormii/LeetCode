class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        
        const int n = 'z'-'a'+1;
        vector<vector<long long>> dp(n,vector<long long>(n, -1));

        for(int i = 0; i < n; ++i)
            dp[i][i] = 0;

        for(int i = 0; i < original.size(); ++i)
        {
            int a = original[i]-'a', b = changed[i]-'a', c = cost[i];
            
            if(dp[a][b] == -1)
                dp[a][b] = c;
            else
                dp[a][b] = min(dp[a][b], static_cast<long long>(c));
        }

        for(int k = 0; k < n; ++k)
            for(int i = 0; i < n; ++i)
                for(int j = 0; j < n; ++j)
                {
                    if(dp[i][k] == -1 || dp[k][j] == -1)
                        continue;
                    
                    if(dp[i][j] == -1)
                        dp[i][j] = dp[i][k] + dp[k][j];
                    else
                        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
                }


        long long ans = 0ll;
        for(int i = 0; i < source.size(); ++i)
        {
            int sChar = source[i] - 'a';
            int tChar = target[i] - 'a';
            if(dp[sChar][tChar] == -1)
                return -1;

            ans += dp[sChar][tChar];
        }

        return ans;
    }
};