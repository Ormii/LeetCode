class Solution {
public:
    int countLatticePoints(vector<vector<int>>& circles) {
        sort(circles.begin(), circles.end(),[&](vector<int>& obj1, vector<int>& obj2){
            return obj1[2] > obj2[2];
        });

        vector<vector<int>> v;
        int minX = numeric_limits<int>::max(), minY = numeric_limits<int>::max();
        int maxX = numeric_limits<int>::min(), maxY = numeric_limits<int>::min();
        for(int i = 0; i < circles.size(); i++)
        {
            int targetX = circles[i][0], targetY = circles[i][1];
            int targetR = circles[i][2];

            bool isInRange = false;
            for(int j = 0; j < v.size() && !isInRange; ++j)
            {
                int compX = v[j][0], compY = v[j][1], compR = v[j][2];
                if((compX - targetX)*(compX - targetX) + (compY - targetY)*(compY - targetY) <= (compR - targetR)*(compR - targetR))
                    isInRange = true;
            }

            if(isInRange)
                continue;

            v.push_back({targetX,targetY,targetR});
            
            minX = min(minX, targetX - targetR);
            minY = min(minY, targetY - targetR);
            maxX = max(maxX, targetX + targetR);
            maxY = max(maxY, targetY + targetR);
        }

        int answer = 0;
        for(int i = minX; i <= maxX; ++i)
        {
            for(int j = minY; j <= maxY; ++j)
            {
                bool isExist = false;
                for(int k = 0; k < v.size() && !isExist; ++k)
                {
                    int compX = v[k][0], compY = v[k][1], compR = v[k][2];
                    if((compX - i)*(compX - i) + (compY - j)*(compY - j) <= compR*compR)
                        isExist = true;
                }

                if(isExist)
                    answer++;
            }
        }

        return answer;
    }
};