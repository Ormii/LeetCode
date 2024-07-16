class Solution {
public:
    vector<int> func(int ind, int prev, vector<int>& nums, vector<vector<vector<int>>>& dp)
    {
        if(ind >= nums.size())
            return vector<int>();

        if(dp[ind][prev + 1].size() != 0)
            return dp[ind][prev + 1];

        vector<int> take = {};
        if(prev == -1 || (nums[ind] % nums[prev]) == 0)
        {
            take = func(ind+1, ind, nums, dp);
            take.insert(take.begin(), nums[ind]);
        }

        vector<int> nontake = func(ind+1, prev, nums, dp);

        dp[ind][prev + 1] = (take.size() > nontake.size()) ? take : nontake;
        return dp[ind][prev + 1];
    }

    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<vector<vector<int>>> dp(nums.size(), vector<vector<int>>(nums.size() + 1));
        sort(nums.begin(), nums.end());
        return func(0,-1,nums,dp);
    }
};