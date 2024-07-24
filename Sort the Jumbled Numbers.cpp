class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int,int>> converts;
        for(int i = 0; i < nums.size(); ++i)
            converts.push_back({Convert(mapping, nums[i]), i});

        sort(converts.begin(), converts.end());

        vector<int> ans(nums.size(), 0);
        for(int i = 0; i < converts.size(); ++i)
            ans[i] = nums[converts[i].second];

        return ans;
    }

    int Convert(vector<int>& mapping, int num)
    {
        int digit = 1;
        int result = 0;
        do
        {
            result += digit*mapping[num%10];
            num/=10;
            digit *= 10;
        }while(num != 0);

        return result;
    }
};