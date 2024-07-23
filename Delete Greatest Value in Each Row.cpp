class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        priority_queue<int>* pq = new priority_queue<int>[m];
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
                pq[i].push(grid[i][j]);
        }

        int ans = 0;
        while(n--)
        {
            int maxval = 0;
            for(int i = 0; i < m; ++i)
            {
                maxval = max(maxval,pq[i].top());
                pq[i].pop();
            }

            ans += maxval;
        }

        return ans;
    }
};