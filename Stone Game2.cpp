class Solution {

public:
    int stoneGameII(vector<int>& piles) {
        vector<vector<int>> memo(piles.size(),vector<int>(piles.size()));
        vector<int> suffixSum = piles;
        for(int i = piles.size() - 2; i >= 0; --i)
            suffixSum[i] += suffixSum[i+1];

        return maxStones(suffixSum, 1, 0, memo);
    }

    int maxStones(vector<int>& suffixSum, int maxTillNow, int currentIdx,vector<vector<int>>& memo)
    {
        if(currentIdx + 2*maxTillNow >= suffixSum.size())
            return suffixSum[currentIdx];
        if(memo[currentIdx][maxTillNow] > 0)
            return memo[currentIdx][maxTillNow];

        int res = numeric_limits<int>::max();
        for(int i = 1; i <= 2*maxTillNow; ++i)
        {
            res = min(res, maxStones(suffixSum, max(i, maxTillNow),currentIdx + i, memo));
        }

        memo[currentIdx][maxTillNow] = suffixSum[currentIdx] - res;
        return memo[currentIdx][maxTillNow];
    }


};