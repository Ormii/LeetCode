class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> left(n, 0);
        vector<int> right(n, 0);

        int leftMaxHeight = height[n-1];
        int rightMaxHeight = height[0];

        for(int i = 0; i < n; ++i)
        {
            leftMaxHeight = max(leftMaxHeight, height[n-1 - i]);
            rightMaxHeight = max(rightMaxHeight, height[i]);

            left[n-1-i] = leftMaxHeight;
            right[i] = rightMaxHeight;
        }

        int ans = 0;
        for(int i = 0; i < n; ++i)
            ans += (min(left[i], right[i])) - height[i];

        return ans;
    }
};