class Solution {
    int ans = 0;
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();

        vector<vector<bool>> check(m, vector<bool>(n,false)); 
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j)
            {
                if(grid[i][j] == '1' && check[i][j] == false)
                {
                    ans++;
                    check[i][j] = true;
                    bfs(grid, check, i, j);
                }
            }
        
        return ans;
    }

    void bfs(vector<vector<char>>& grid, vector<vector<bool>>& check, int startY, int startX)
    {
        int m = grid.size(), n = grid[0].size();

        queue<pair<int,int>> que;
        que.push({startY,startX});

        while(!que.empty())
        {
            int y = que.front().first;
            int x = que.front().second;
            que.pop();

            for(int i = 0; i < 4; ++i)
            {
                int dx[4] = {0,0,-1,1};
                int dy[4] = {1,-1,0,0};

                int yy = y + dy[i];
                int xx = x + dx[i];
                if(xx < 0 || xx >= n || yy < 0 || yy >= m)
                    continue;
                if(grid[yy][xx] == '0')
                    continue;
                if(check[yy][xx] == true)
                    continue;

                check[yy][xx] = true;
                que.push({yy,xx});
            } 
        }
    }
};