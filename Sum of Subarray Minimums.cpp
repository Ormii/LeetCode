class Solution {
    static int mod;
public:
    int sumSubarrayMins(vector<int>& arr) {
        int length = arr.size();
        vector<int> left(length, 0);
        vector<int> right(length, 0);

        stack<pair<int,int>> st = stack<pair<int,int>>();
        for(int i = 0; i < length; ++i)
        {
            int cnt = 1;
            while(!st.empty() && st.top().first > arr[i])
            {
                cnt += st.top().second;
                st.pop();
            }

            st.push({arr[i], cnt});
            left[i] = cnt;
        }

        st = stack<pair<int,int>>();
        for(int i = length-1; i >= 0; --i)
        {
            int cnt = 1;
            while(!st.empty() && st.top().first >= arr[i])
            {
                cnt += st.top().second;
                st.pop();
            }

            st.push({arr[i], cnt});
            right[i] = cnt;
        }

        int ans = 0;
        for(int i = 0; i < length; ++i)
        {
            ans = (ans + (arr[i]*(long long)(left[i]*right[i]%mod))%mod)%mod;
        }

        return ans;
    }
};

int Solution::mod = 1000000007;