class Solution {
public:
    int incremovableSubarrayCount(vector<int>& nums) {
        int ans = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = i; j < nums.size(); j++)
            {
                bool check = false;
                int prev = 0;
                for(int k = 0; k < nums.size() && !check; k++)
                {
                    if(k >= i && k <=j)
                        continue;

                    if(prev >= nums[k])
                    {
                        check = true;
                        break;
                    }

                    prev = nums[k];
                }

                if(check == false)
                    ans++;
            }    
        }

        return ans;
    }
};