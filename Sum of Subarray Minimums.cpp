class Solution {
    static int mod;
public:
    int sumSubarrayMins(vector<int>& arr) {

        queue<tuple<int,int,int>> que;

        int minVal = numeric_limits<int>::max();
        int ans = 0;
        for(int i = 0; i < arr.size(); ++i)
        {
            que.push({i,i,arr[i]});
            minVal = min(minVal, arr[i]);
        }

        while(!que.empty())
        {
            auto[i,j,dp] = que.front();
            que.pop();

            ans = (ans + dp)%mod;

            if(j+1<arr.size())
            {
                if(dp == minVal)
                {
                    ans = (ans + (minVal*(arr.size() - (j+1))%mod))%mod;
                }
                else
                {
                    que.push({i,j+1,min(dp,arr[j+1])});
                }
            }
        }

        return ans;
    }
};

int Solution::mod = 1000000007;