class Solution {
public:
    long long solve(vector<long long>& dp,int n, int i, vector<int>& indices, vector<int>& primes)
    {
        if(n == i)
            return dp[n-1];
        
        long long nextUgly = numeric_limits<int>::max();
        for(int j = 0; j < primes.size(); ++j)
            nextUgly = min(nextUgly, dp[indices[j]]*primes[j]);

        dp[i] = nextUgly;

        for(int j = 0; j <primes.size(); ++j)
        {
            if(dp[indices[j]] * primes[j] == nextUgly)
                indices[j]++;
        }

        return solve(dp, n, i+1, indices, primes);
    }

    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<long long> dp(n, -1);
        dp[0] = 1;
        vector<int> indices(primes.size(),0);

        return solve(dp, n, 1,indices,primes);
    }
};