class Solution {
public:
    int numTeams(vector<int>& rating) {
        int answer = 0;

        vector<vector<int>> IncDp(rating.size(), vector<int>(4,-1));
        vector<vector<int>> DescDp(rating.size(), vector<int>(4,-1));
        for(int i = 0; i < rating.size(); ++i)
        {
            answer += IncRecursive(rating, IncDp, i, 1);
            answer += DescRecursive(rating, DescDp, i, 1);
        }

        return answer;
    }

    int IncRecursive(vector<int>& rating, vector<vector<int>>& dp, int i, int curSize)
    {
        if(i == rating.size())
            return 0;

        if(curSize == 3)
            return 1;
        
        if(dp[i][curSize] != -1)
            return dp[i][curSize];

        int result = 0;
        for(int next = i + 1; next < rating.size() ; ++next)
        {
            if(rating[i] < rating[next])
            {
                result += IncRecursive(rating, dp, next, curSize+1); 
            }
        }
        
        dp[i][curSize] = result;
        return dp[i][curSize];
    }

    int DescRecursive(vector<int>& rating, vector<vector<int>>& dp, int i, int curSize)
    {
         if(i == rating.size())
            return 0;
        
        if(curSize == 3)
            return 1;

        if(dp[i][curSize] != -1)
            return dp[i][curSize];

        int result = 0;
        for(int next = i + 1; next < rating.size() ; ++next)
        {
            if(rating[i] > rating[next])
            {
                result += DescRecursive(rating, dp, next, curSize+1); 
            }
        }
        
        dp[i][curSize] = result;
        return dp[i][curSize];
    }
};