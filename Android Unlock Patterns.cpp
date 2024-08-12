class Solution {
public:
    int numberOfPatterns(int m, int n) {
        int totalPatterns = 0;
        for(int row = 0; row < 3; ++row)
        {
            for(int col = 0; col < 3; ++col)
            {
                vector<vector<bool>> visited(3,vector<bool>(3,false));
                totalPatterns += countPattern(m,n,row,col,visited,1);
            }
        }

        return totalPatterns;
    }

private:
    const vector<vector<int>> SINGLE_STEP_MOVES=
    {
        { 1, 0}, { 0, 1},
        {-1, 0}, { 0,-1},
        { 1, 1}, { 1,-1},
        {-1, 1}, {-1,-1},
        {-2, 1}, { 2,-1},
        { 1,-2}, {-1, 2},
        { 2, 1}, { 1, 2},
        {-2,-1}, {-1,-2}
    };

    const vector<vector<int>> SKIP_DOT_MOVES = {
        { 0, 2}, { 0,-2},
        { 2, 0}, {-2, 0},
        {-2,-2}, { 2, 2},
        { 2,-2}, {-2, 2}
    };

    int countPattern(int m, int n, int i, int j, vector<vector<bool>>& check, int currentLength)
    {
        if(n < currentLength)
            return 0;

        int count = 0;
        if(currentLength >= m)
            count++;

        check[i][j] = true;

        for(int idx = 0; idx < SINGLE_STEP_MOVES.size(); ++idx)
        {
            int row = i + SINGLE_STEP_MOVES[idx][0];
            int col = j + SINGLE_STEP_MOVES[idx][1];
            
            if(isValidMove(row,col,check) == false)
                continue;
            
            count += countPattern(m,n,row,col,check,currentLength+1);
        }

        for(int idx = 0; idx < SKIP_DOT_MOVES.size(); ++idx)
        {
            int row = i + SKIP_DOT_MOVES[idx][0];
            int col = j + SKIP_DOT_MOVES[idx][1];
            
            if(isValidMove(row,col,check) == false)
                continue;

            int middleRow = i + SKIP_DOT_MOVES[idx][0]/2;
            int middleCol = j + SKIP_DOT_MOVES[idx][1]/2;
            
            if(check[middleRow][middleCol] == false)
                continue;

            count += countPattern(m,n,row,col,check,currentLength+1);
        }

        check[i][j] = false;
        return count;
    }

    bool isValidMove(int row, int col, vector<vector<bool>>& check)
    {
        return row >= 0 && row < 3 && col >= 0 && col < 3 && !check[row][col];
    }
};