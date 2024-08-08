class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> answer;
        vector<vector<int>> dir = {{0,1},{1,0},{0,-1},{-1,0}};

        int step = 1;
        int curdir = 0;
        answer.push_back({rStart, cStart});
        while(answer.size() != rows*cols)
        {
            for(int i = 0; i < 2; ++i)
            {
                for(int j = 0; j < step; ++j)
                {
                    rStart += dir[curdir][0];
                    cStart += dir[curdir][1];

                    if(rStart >= 0 && rStart < rows && cStart >= 0 && cStart < cols)
                        answer.push_back({rStart,cStart});
                }

                curdir = (curdir + 1)%4;
            }

            step++;
        }

        return answer;
    }
};