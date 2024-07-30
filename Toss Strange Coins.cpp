class Solution {

public:
    double probabilityOfHeads(vector<double>& prob, int target) {
        int n = prob.size();
        vector<vector<double>> dp(prob.size(), vector<double>(target+1, -1));

        double answer = 0;
        answer = recursive(prob, dp, target, 0);

        return answer;
    }

    double recursive(vector<double>& prob,vector<vector<double>>& dp, int target, int i)
    {
        if(target < 0)
            return 0.0;

        if(i == prob.size())
        {
            if(target == 0)
                return 1.0f;
            else
                return 0.0f;
        }

        if(dp[i][target] != -1)
            return dp[i][target];

        dp[i][target] = (1- prob[i])*recursive(prob,dp,target,i+1);
        dp[i][target] += prob[i]*recursive(prob,dp,target - 1, i+1);
    
        return dp[i][target];
    }
};