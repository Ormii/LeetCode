class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        QuickSort(nums, 0, nums.size() - 1);

        return nums;
    }

    void QuickSort(vector<int>& nums, int left, int right)
    {
        if(left>=right)
            return;

        int pivotIndex = (left + right)/2;
        int storeIndex = left;
        swap(nums[pivotIndex], nums[right]);
        
        for(int i = left ; i < right; ++i)
        {
            if(nums[i] < nums[right])
                swap(nums[storeIndex++], nums[i]);
        }

        pivotIndex = storeIndex;
        swap(nums[pivotIndex], nums[right]);
        QuickSort(nums, left, pivotIndex - 1);
        QuickSort(nums, pivotIndex + 1, right);
    }
};