class Solution {


public:
    int minDifference(vector<int>& nums) {
        if(nums.size() <=4)
            return 0;
        
        sort(nums.begin(), nums.end());

        int minValue = numeric_limits<int>::max();

        for(int i = 0; i <= 3; ++i)
            minValue = min(minValue, nums[nums.size() - (3-i) - 1] - nums[i]);

        return minValue;
    }
};