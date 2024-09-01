class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if(original.size() != m*n)
            return vector<vector<int>>();

        vector<vector<int>> answer(m,vector<int>(n,0));
        
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j)
            {
                int index = i*n + j;
                if(index >= original.size())
                    continue;

                answer[i][j] = original[index];
            }
                
        return answer;
    }
};