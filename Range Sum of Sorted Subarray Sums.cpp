class Solution {

const int mod = 1000000007;
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> prefixSum(n + 1, 0);
        for(int i = 0; i < n; ++i)
            prefixSum[i+1] = prefixSum[i] + nums[i];

        vector<int> con;
        for(int i = 0; i < n; ++i)
            for(int j = i + 1; j <= n; ++j)
                con.push_back(prefixSum[j] - prefixSum[i]);

        int answer = 0;
        sort(con.begin(),con.end());
        for(int i = left-1; i <= right-1; ++i)
            answer = (answer + con[i])%mod;
    
        return answer;
    }
};