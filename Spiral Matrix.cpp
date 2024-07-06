class Solution {

public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        int n = matrix.size(), m = matrix[0].size();
        int Dir = 0;
        int dx[4] = {1,0,-1,0};
        int dy[4] = {0,1,0,-1};
        int curX = 0, curY = 0;
        bool bNextMoveExist = false;

        vector<int> ans;
        vector<vector<bool>> bMoved(n, vector<bool>(m,false));

        do
        {
            ans.push_back(matrix[curY][curX]);
            bMoved[curY][curX] = true;
            
            bNextMoveExist = false;
            for(int i = 0; i <= 3 && !bNextMoveExist; ++i)
            {
                int NextDir = ((int)Dir + i) % 4;
                int NextX = curX + dx[NextDir], NextY = curY + dy[NextDir];

                if(IsInRange(NextX, NextY, n, m) && bMoved[NextY][NextX] == false)
                {
                    bNextMoveExist = true;
                    curX = NextX;
                    curY = NextY;
                    Dir = NextDir;
                }
            }
        }while(bNextMoveExist);

        return ans;
    }

    bool IsInRange(int x, int y, int n, int m)
    {
        return 0 <= x && x < m && 0 <= y && y < n;
    }
};