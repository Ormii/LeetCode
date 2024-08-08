class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> answer(2,0);
        for(int i = 0; i < nums.size(); ++i)
        {
            int remain = target - nums[i];
            auto iter = find(nums.begin() + i + 1, nums.end(), remain);
            if(iter != nums.end())
            {
                answer[0] = i;
                answer[1] = iter - nums.begin();
                return answer;
            }
        }

        return vector<int>();
    }
};