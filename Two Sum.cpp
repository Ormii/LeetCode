class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> answer(2,0);
        for(int i = 0; i < nums.size(); ++i)
        {
            int remainTarget = target - nums[i];
            for(int j = i + 1; j < nums.size(); ++j)
                if(nums[j] == remainTarget)
                {
                    answer[0] = i;
                    answer[1] = j;
                    return answer;
                }
        }

        return answer;
    }
};