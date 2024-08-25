class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        
        while(k--)
        {
            int i = 0, minValue = numeric_limits<int>::max();
            int idx = 0;
            for(i = 0; i < nums.size(); ++i)
            {
                if(minValue > nums[i])
                {
                    idx = i;
                    minValue = nums[i];
                }
            }

            nums[idx] = nums[idx]*multiplier;
        }

        return nums;
    }
};