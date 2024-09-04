class Solution {

    static const int HASH_MULTIPLYER = 60001;

private:
    int HashCoordinate(int x, int y)
    {
        return x + HASH_MULTIPLYER * y;
    }

public:

    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) 
    { 
        int maxDistance = 0;

        vector<vector<int>> directions = {{0,1},{1,0},{0,-1},{-1,0}};
        unordered_set<int> us;
        for(auto &obstacle: obstacles)
            us.insert(HashCoordinate(obstacle[0], obstacle[1]));

        int currentDirection = 0;
        vector<int> currentPosition = {0,0};
        for(int i = 0; i < commands.size(); ++i)
        {
            int command = commands[i];
            if(command == -2)
            {
                currentDirection = ((int)currentDirection +3)%4;
            }
            else if(command == -1)
                currentDirection = ((int)currentDirection +1)%4;
            else
            {
                vector<int> direction = directions[currentDirection];
                for(int step = 0; step < command; step++)
                {
                    int nextX = currentPosition[0] + direction[0];
                    int nextY = currentPosition[1] + direction[1];

                    if(us.find(HashCoordinate(nextX, nextY))!= us.end())
                        break;

                    currentPosition[0] = nextX;
                    currentPosition[1] = nextY;

                maxDistance = max(maxDistance, currentPosition[0]*currentPosition[0] + currentPosition[1]*currentPosition[1]);
                }
            }
        }
        int result = maxDistance; 
        return result;
    }
};