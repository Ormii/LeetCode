class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        vector<vector<bool>> table(n*3, vector<bool>(n*3, false));
        vector<vector<bool>> check(n*3, vector<bool>(n*3, false));
        int px = 0, py = 0;
        for(int i = 0; i < n; ++i)
        {
            py = i*3;
            for(int j = 0; j < n; ++j)
            {
                px = j*3;
                char c = grid[i][j];
                if(c == '\\')
                {
                    check[py][px] = table[py][px] = true;
                    check[py+1][px+1] = table[py+1][px+1] = true;
                    check[py+2][px+2] = table[py+2][px+2] = true;
                }
                else if(c == '/')
                {
                    check[py][px+2] = table[py][px+2] = true;
                    check[py+1][px+1] = table[py+1][px+1] = true;
                    check[py+2][px] = table[py+2][px] = true;
                }
            }
        }

        int answer = 0;
        for(int i = 0; i < n*3; ++i)
        {
            for(int j = 0; j < n*3; ++j)
            {
                if(check[i][j] == false)
                {
                    answer++;
                    bfs(table,check,i,j);
                }
            }
        }

        return answer;
    }

    void bfs(vector<vector<bool>>& table, vector<vector<bool>>& check, int startY, int startX)
    {
        int n = table.size();

        queue<pair<int,int>> que;
        check[startY][startX] = true;
        que.push({startY,startX});

        while(!que.empty())
        {
            int y = que.front().first;
            int x = que.front().second;
            que.pop();

            int dy[4] = {-1,1,0,0};
            int dx[4] = {0,0,1,-1};
            
            for(int i = 0; i < 4; ++i)
            {
                int yy = y + dy[i], xx = x + dx[i];
                if(yy < 0 || xx < 0 || yy >= n || xx >= n)
                    continue;
                
                if(check[yy][xx])
                    continue;
                if(table[yy][xx])
                    continue;

                check[yy][xx] = true;
                que.push({yy, xx});
            }
        }
    }
};