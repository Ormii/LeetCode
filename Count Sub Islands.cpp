class Solution {
public:
    bool isInRange(vector<vector<int>>& grid, int y, int x)
    {
        int m = grid.size();
        int n = grid[0].size();

        return (y >= 0 && y < m && x >= 0 && x < n);
    }

    bool bfs(vector<vector<int>>& grid, vector<vector<int>>& targetgrid,vector<vector<bool>>& check,int startY, int startX)
    {
        queue<pair<int,int>> que;
        check[startY][startX] = true;
        que.push({startY, startX});
        
        bool isSubIsland = true;
        while(!que.empty())
        {
            auto[y,x] = que.front();
            que.pop();

            if(targetgrid[y][x] == 0)
                isSubIsland = false;

            int dy[4] = {-1,1,0,0};
            int dx[4] = {0,0,1,-1};

            for(int i = 0; i < 4; ++i)
            {
                int yy = y + dy[i], xx = x + dx[i];
                if(!isInRange(grid, yy, xx))
                    continue;
                if(check[yy][xx] || grid[yy][xx] == 0)
                    continue;

                check[yy][xx] = true;
                que.push({yy, xx});
            }
        }

        return isSubIsland;
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid1.size(), n = grid1[0].size();
        
        vector<vector<bool>> check(m, vector<bool>(n, false));

        int answer = 0;
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(check[i][j] || grid2[i][j] == 0)
                    continue;
        
                answer += bfs(grid2,grid1,check,i,j);
            }
        }

        return answer;
    }
};