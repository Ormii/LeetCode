class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> v;

        for(auto& num : nums)
        {
            auto iter = lower_bound(v.begin(), v.end(), num);
            if(iter == v.end())
                v.push_back(num);
            else
                *iter = num;
        }

        return v.size();
    }
};