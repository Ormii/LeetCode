class Solution {
private:
    int dp[100001];

public:
    int maxProfit(vector<int>& prices) {
        int minVal = prices[0];
        for(int i = 1; i <prices.size(); ++i)
        {
            minVal = min(prices[i], minVal);
            dp[i] = max(dp[i-1], prices[i] - minVal);
        }

        int maxVal = 0;
        for(int i = 0; i < prices.size(; ++i)
            maxVal = max(dp[i], maxVal);)

        return maxVal;
    }
};