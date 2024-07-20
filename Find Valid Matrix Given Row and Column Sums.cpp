class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        
        int n = rowSum.size();
        int m = colSum.size();
        vector<vector<int>> ans(n, vector<int>(m));

        for(int i = 0; i < n ; ++i)
        {
            for(int j = 0; j < m; ++j)
            {
                if(rowSum[i] < colSum[j])
                    ans[i][j] = rowSum[i];
                else
                    ans[i][j] = colSum[j];
            
                rowSum[i] -= ans[i][j];
                colSum[j] -= ans[i][j];
            }
        }

        return ans;
    }
};