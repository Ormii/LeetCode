class Solution {
    typedef struct Robot
    {
        int position;
        int* phealth;
        int index;

        explicit Robot(int pos, int idx, int* php)
        {
            position = pos;
            index = idx;
            phealth = php;
        }

        bool operator< (const Robot& other) const
        {
            return position < other.position;
        }
    }Robot;

public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        vector<Robot> LeftMoveRobots;
        vector<Robot> RightMoveRobots;

        int n = positions.size();
        for(int i = 0; i < n; ++i)
        {
            if(directions[i] == 'R')
                RightMoveRobots.push_back(Robot{positions[i],i, &healths[i]});
            else
                LeftMoveRobots.push_back(Robot{positions[i],i, &healths[i]});
        }

        sort(LeftMoveRobots.begin(), LeftMoveRobots.end(), [&](const Robot& obj1, const Robot& obj2)->bool{
            return obj1.position < obj2.position;
        });

        sort(RightMoveRobots.begin(), RightMoveRobots.end(), [&](const Robot& obj1, const Robot& obj2)->bool{
            return obj1.position < obj2.position;
        });

        for(int i = 0; i < LeftMoveRobots.size(); ++i)
        {
            auto iter = std::upper_bound(RightMoveRobots.begin(), RightMoveRobots.end(), LeftMoveRobots[i]);
            if(iter == RightMoveRobots.begin())
                continue;

            int index = (iter - 1) - RightMoveRobots.begin(); 
            for(; index >= 0; --index)
            {   
                int* pLeftHealth = LeftMoveRobots[i].phealth;
                int* pRightHealth = RightMoveRobots[index].phealth;

                if(*pRightHealth == 0)
                    continue;

                if(*pRightHealth == *pLeftHealth)
                {
                    *pRightHealth = 0;
                    *pLeftHealth = 0;
                    break;
                }
                else if(*pRightHealth > *pLeftHealth)
                {
                    *pRightHealth -= 1;
                    *pLeftHealth = 0;
                    break;
                }
                else
                {
                    *pRightHealth = 0;
                    *pLeftHealth -= 1;
                }
            }
        }

        vector<int> ans;
        for(int i = 0; i < n; ++i)
        {
            if(healths[i] != 0)
                ans.push_back(healths[i]);
        }

        return ans;
    }
};