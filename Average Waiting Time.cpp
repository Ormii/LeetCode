class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        vector<int> waittimes;
        int time = 0;
        for(auto& customer : customers)
        {
            int arrival = customer[0];
            int wait = customer[1];

            if(time <= arrival)
            {
                waittimes.push_back(wait);
                time = arrival + wait;
            }
            else
            {
                waittimes.push_back(time - arrival + wait);
                time += wait;
            }
        }

        double totWaitTime = 0;
            for(auto waittime : waittimes)
                totWaitTime += waittime;
        double ans = totWaitTime / waittimes.size();
        return ans;
    }
};