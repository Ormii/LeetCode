class Solution {
    int dp[50001];
public:
    int findMaxProfit(vector<vector<int>>& jobs, vector<int>& startTime, int position)
    {
        int n = startTime.size();
        if(position == n)
            return 0;

        if(dp[position] != -1)
            return dp[position];
        

        int nextPosition = lower_bound(startTime.begin(), startTime.end(), jobs[position][1]) - startTime.begin();
        int profit = max(findMaxProfit(jobs, startTime, position + 1), jobs[position][2] + findMaxProfit(jobs, startTime, nextPosition));
        
        return dp[position] = profit;
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> jobs;
        memset(dp, -1, sizeof(dp));

        for(int i = 0; i < startTime.size(); ++i)
            jobs.push_back({startTime[i], endTime[i], profit[i]});

        sort(jobs.begin(), jobs.end());

        for(int i = 0; i < startTime.size(); ++i)
            startTime[i] = jobs[i][0];

        return findMaxProfit(jobs, startTime, 0);
    }   
};