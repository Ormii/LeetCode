class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> ans;
        for(int i = 0; i < n ; ++i)
        {
            for(int j = 0; j < m; ++j)
            {
                bool isColMaximum = true;
                for(int k = 0; k < n && isColMaximum; ++k)
                    isColMaximum = matrix[k][j] <= matrix[i][j];

                bool isRowMinimum = true;
                for(int k = 0; k < m && isRowMinimum; ++k)
                    isRowMinimum = matrix[i][k] >= matrix[i][j];
            
                if(isRowMinimum && isColMaximum)
                    ans.push_back(matrix[i][j]);
            }
        }

        return ans;
    }
};