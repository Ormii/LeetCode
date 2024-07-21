class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n,0));
        int ans = dfs(0,0,m,n,dp);

        return ans;
    }

    int dfs(int cury,int curx, int m, int n, vector<vector<int>>& dp)
    {
        if(dp[cury][curx] != 0)
            return dp[cury][curx];

        if(cury == m - 1 && curx == n - 1)
        {
            dp[cury][curx] = 1;
            return dp[cury][curx];
        }

        int dy[2] = {0, 1};
        int dx[2] = {1, 0};

        int val = 0;
        for(int i = 0; i < 2; ++i)
        {
            int xx = curx + dx[i];
            int yy = cury + dy[i];

            if(yy >= m || xx >= n)
                continue;

            val += dfs(yy,xx,m,n,dp);
        }

        dp[cury][curx] = val;
    
        return dp[cury][curx];
    }
};