class Solution {
public:
    void bfs(vector<vector<int>>& grid, vector<vector<bool>>& check, int i, int j)
    {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> que;
        que.push({i,j});

        while(!que.empty())
        {
            auto[y,x] = que.front();
            que.pop();

            int dy[4] = {-1,1,0,0};
            int dx[4] = {0,0,1,-1};
            
            for(int i = 0; i < 4; ++i)
            {
                int yy = y + dy[i], xx = x + dx[i];
                if(yy < 0 || xx < 0 || yy >= n || xx >= m)
                    continue;
                if(check[yy][xx] == true)
                    continue;
                if(grid[yy][xx] == 0)
                    continue;

                check[yy][xx] = true;
                que.push({yy,xx});
            }
        }
    }

    int getIslandCount(vector<vector<int>>& grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> check(n, vector<bool>(m, false));

        int count = 0;
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < m; ++j)
            {
                if(check[i][j] == false && grid[i][j] == 1)
                {
                    count++;
                    bfs(grid,check,i,j);
                }
            }
        }

        return count;
    } 

    int minDays(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        if(getIslandCount(grid) != 1)
            return 0;

        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < m; ++j)
            {
                if(grid[i][j] == 0)
                    continue;

                grid[i][j] = 0;

                if(getIslandCount(grid) != 1)
                    return 1;

                grid[i][j] = 1;
            }
        }

        return 2;
    }
};