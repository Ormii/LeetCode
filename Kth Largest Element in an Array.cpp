class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        k-=1;
        priority_queue<int> pq;
        for(auto& num : nums)
            pq.push(num);

        while(k-->0)
            pq.pop();

        int ans = pq.top();
        return ans;
    }
};