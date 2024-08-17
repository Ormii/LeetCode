class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int m = points[0].size();
        vector<vector<long long>> memo(n,vector<long long>(m,numeric_limits<long long>::min()));
        for(int i = 0; i < m ; ++i)
            memo[0][i] = points[0][i];

        for(int i = 1; i < n; ++i)
        {
            auto& currentRow = memo[i];
            auto& prevRow = memo[i-1];

            vector<long long> leftMax(m);
            vector<long long> rightMax(m);

            leftMax[0] = prevRow[0];
            for(int j = 1; j < m; ++j)
                leftMax[j] = max(leftMax[j-1] - 1, prevRow[j]);

            rightMax[m-1] = prevRow[m-1];
            for(int j = m-2; j >= 0; --j)
                rightMax[j] = max(rightMax[j+1] - 1, prevRow[j]); 

            for(int j = 0; j < m; ++j)
                currentRow[j] = max(leftMax[j],rightMax[j]) + points[i][j];
        }    
        
        return *max_element(memo[n-1].begin(), memo[n-1].end());
    }
};