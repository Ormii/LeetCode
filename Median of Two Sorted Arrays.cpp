class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
   
        if(nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2,nums1);

        int left = 0, right = (int)nums1.size();
        while(left <= right)
        {
            int partitionX = (left + right)/2;
            int partitionY = (nums1.size() + nums2.size() + 1)/2- partitionX;

            int maxLeftX = (partitionX == 0) ? numeric_limits<int>::min() : nums1[partitionX-1];
            int minRightX = (partitionX == nums1.size()) ? numeric_limits<int>::max() : nums1[partitionX];

            int maxLeftY = (partitionY == 0) ? numeric_limits<int>::min() : nums2[partitionY-1];
            int minRightY = (partitionY == nums2.size()) ? numeric_limits<int>::max() : nums2[partitionY];
            
            if(maxLeftX <= minRightY && minRightX >= maxLeftY)
            {
                if((nums1.size() + nums2.size())%2 == 0)
                    return (max(maxLeftX,maxLeftY) + min(minRightX, minRightY))*0.5f;
                else
                    return max(maxLeftX,maxLeftY);
            }
            else if(maxLeftX > minRightY)
            {
                right = partitionX - 1;
            }
            else
            {
                left = partitionX + 1;
            }
        }

        return 0;
    }
};