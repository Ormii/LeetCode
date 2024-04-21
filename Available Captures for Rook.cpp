class Solution {

typedef struct _pos
{
    int _x;
    int _y;
}Pos;

private:
    int m_MaxRow = 8;
    int m_MaxCol = 8;

public:
    int numRookCaptures(vector<vector<char>>& board) {
        int ans = 0;
        Pos rockPos;
        for(int i = 0; i < board.size(); i++)
        {
            for(int j = 0; j < board[i].size(); j++)
            {
                if(board[i][j] == 'R')
                {
                    rockPos._y = i;
                    rockPos._x = j;
                    break;
                }
            }
        }

        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};
        for(int i = 0; i < 4; i++)
        {
            for(int scale = 1; scale < 8; ++scale)
            {
                int xx = rockPos._x + dx[i]*scale, yy = rockPos._y + dy[i]*scale;
                if(xx < 0 || yy < 0|| xx >= m_MaxCol || yy >= m_MaxRow)
                    break;

                if(board[yy][xx] == '.')
                    continue;
                else
                {
                    if(board[yy][xx] == 'p')
                        ans++;
                    
                    break;
                }
            }
        }

        return ans;
    }
};