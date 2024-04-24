class Solution {
public:
    int maxNumberOfApples(vector<int>& weight) {
        int ans = 0;
        int capacity = 0;
        sort(weight.begin(), weight.end());
        for(auto w : weight)
        {
            if(capacity + w > 5000)
                break;
            ans++;
            capacity += w;
        }

        return ans;
    }
};