class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);
        for(int i = 0; i < dp.size(); ++i)
        {
            switch(i)
            {
                case 0:
                    dp[i] = nums[i];
                    break;
                case 1:
                    dp[i] = max(nums[i], nums[i-1]);
                    break;
                default:
                    dp[i] = max(dp[i-2] + nums[i], dp[i-1]);
                    break;
            }
        }

        return dp[dp.size()-1];
    }
};