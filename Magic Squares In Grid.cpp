class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int answer = 0;
        for(int i = 0; i+2 < grid.size(); ++i)
        {
            for(int j = 0; j+2 <grid[i].size(); ++j)
            {
                unordered_set<int> us;
                for(int k = i; k <= i+2; k++)
                    for(int l = j; l <= j+2; l++)
                        if(grid[k][l] < 10)
                            us.insert(grid[k][l]);

                if(us.size() != 9)
                    continue;
                
                if(grid[i][j] + grid[i+1][j+1] + grid[i+2][j+2] != 15)
                    continue;
                if(grid[i+2][j] + grid[i+1][j+1] + grid[i][j+2] != 15)
                    continue;
                
                bool isMagicSquare = true;
                
                for(int k = i; k <= i+2 && isMagicSquare; k++)
                {
                    int sum_of_elems = 0;
                    for(int l = j; l <= j+2; l++)
                        sum_of_elems += grid[k][l];

                    isMagicSquare = sum_of_elems == 15;
                }

                if(isMagicSquare == false)
                    continue;
                    
                for(int l = j; l <= j+2 && isMagicSquare; l++)
                {
                    int sum_of_elems = 0;
                    for(int k = i; k <= i+2; k++)
                        sum_of_elems += grid[k][l];

                    isMagicSquare = sum_of_elems == 15;
                }

                if(isMagicSquare == false)
                    continue;

                answer++;
            }
        }

        return answer;
    }
};