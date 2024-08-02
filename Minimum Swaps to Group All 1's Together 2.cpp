class Solution {
public:
    int minSwaps(vector<int>& nums) {
        
        return min(minSwapHelper(nums,0),minSwapHelper(nums,1));
    }

    int minSwapHelper(vector<int>& data, int val)
    {
        int length = data.size();
        int totalValCount = 0;

        for(int i = length - 1; i >= 0; --i)
            if(data[i] == val) totalValCount++;

        if(totalValCount == 0 || totalValCount == length)
            return 0;

        int start = 0, end = 0;
        int maxValWindow = 0, currentValWindow = 0;

        while(end < totalValCount)
            if(data[end++] == val) currentValWindow++;

        maxValWindow = max(currentValWindow, maxValWindow);

        while(end < length)
        {
            if(data[start++] == val) currentValWindow--;
            if(data[end++] == val) currentValWindow++;

            maxValWindow = max(currentValWindow, maxValWindow);
        }

        return totalValCount - maxValWindow;
    }
};