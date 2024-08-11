class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m=  image[0].size();
        
        vector<vector<bool>> check(n,vector<bool>(m,false));
        queue<pair<int,int>> que;

        que.push({sr,sc});
        check[sr][sc] = true;

        int targetColor = image[sr][sc];
        image[sr][sc] = color;

        while(!que.empty())
        {
            auto[y,x] = que.front();
            que.pop();

            int dy[4] = {-1,1,0,0};
            int dx[4] = {0,0,-1,1};
            for(int i = 0; i < 4; ++i)
            {
                int yy = y + dy[i], xx = x + dx[i];
                if(yy < 0 || xx < 0 || yy >= n || xx >= m)
                    continue;

                if(check[yy][xx])
                    continue;

                if(image[yy][xx] != targetColor)
                    continue;
            
                check[yy][xx] = true;
                image[yy][xx] = color;
                que.push({yy,xx});
            }
        }

        return image;
    }
};