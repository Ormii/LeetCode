class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {

        sort(nums.begin(), nums.end());

        int low = 0;
        int height = nums[nums.size()-1] - nums[0];

        while(low < height)
        {
            int mid = (low + height)/2;

            int count = calcPairDistance(nums,mid);
            if(count < k)
                low = mid+1;
            else
                height = mid;
        }

        return low;
    }

    int calcPairDistance(vector<int>& nums, int distance)
    {
        int count = 0;
        int left = 0;
        for(int right = 0; right < nums.size(); ++right)
        {
            while(nums[right] - nums[left] > distance)
                left++;
            
            count += (right - left);
        }

        return count;
    }
};